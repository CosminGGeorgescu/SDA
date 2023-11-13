use std::{
    collections::VecDeque,
    fs::File,
    io::{BufRead, BufReader, BufWriter, Write},
};

fn solve(writer: &mut BufWriter<File>, n: &u32, p: &u32) {
    let mut q: VecDeque<usize> = VecDeque::from([0]);
    let mut vis = [false; 5000000];

    while !q.is_empty() {
        let curr = unsafe { q.pop_front().unwrap_unchecked() };

        if curr % *p as usize == *n as usize {
            let _ = writer.write(format!("{}\n", curr).as_bytes());
            return;
        }

        for digit in [2, 3, 5, 7] {
            if let Some(next) = curr.checked_mul(10).and_then(|n| n.checked_add(digit)) {
                let r = next % *p as usize;
                if !vis[r] {
                    vis[r] = true;
                    q.push_back(next);
                }
            } else {
                let _ = writer.write(b"-1\n");
                return;
            }
        }
    }
}

fn main() {
    let fin = BufReader::new(File::open("cifre4.in").unwrap());
    let mut fout = BufWriter::new(File::create("cifre4.out").unwrap());
    fin.lines().skip(1).for_each(|line| {
        let args = line
            .unwrap()
            .trim()
            .split_ascii_whitespace()
            .map(|x| unsafe { x.parse::<u32>().unwrap_unchecked() })
            .collect::<Vec<u32>>();
        solve(&mut fout, &args[0], &args[1]);
    });
}
