fn selection_sort(vec: &mut Vec<i32>) {
    for i in 0..(vec.len() - 1) {
        let mut min_index = i;
        for j in (i + 1)..vec.len() {
            if vec[j] < vec[min_index] {
                min_index = j;
            }
        }
        vec.swap(i, min_index)
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).expect("read error");
    let mut numbers = buf
        .trim()
        .split(" ")
        .into_iter()
        .map(|num| num.parse::<i32>().expect("parse error"))
        .collect::<Vec<i32>>();
    selection_sort(&mut numbers);
    println!("{:?}", numbers);
}
