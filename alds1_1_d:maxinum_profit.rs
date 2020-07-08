fn main() {
    let mut data = Vec::with_capacity(200000);
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).expect("read error");
    let n = buf.trim().parse::<usize>().expect("parse error");

    assert!(n <= 200000 && n >= 2);

    for _ in 0..n {
        let mut buf = String::new();
        std::io::stdin().read_line(&mut buf).expect("read error");
        let num = buf.trim().parse::<i32>().expect("parse error");
        data.push(num);
    }

    let mut min = data[0];
    let mut max = data[1] - min;

    for i in 1..n {
        max = std::cmp::max(max, data[i] - min);
        min = std::cmp::min(min, data[i]);
    }

    println!("max profit: {}", max);
}
