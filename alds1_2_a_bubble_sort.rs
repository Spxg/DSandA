fn bubble_sort(vec: &mut Vec<i32>) {
    let len = vec.len();
    let mut break_flag;
    for i in 0.. {
        break_flag = true;
        for j in ((i + 1)..=(len - 1)).rev() {
            if vec[j] <= vec[j - 1] {
                vec.swap(j, j - 1);
                break_flag = false;
            }
        }
        if break_flag { break }
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).expect("read error");
    let mut numbers = buf.trim().split(" ").into_iter()
                    .map(|num| num.parse::<i32>().expect("parse error"))
                    .collect::<Vec<i32>>();
    bubble_sort(&mut numbers);
    println!("{:?}", numbers);
}