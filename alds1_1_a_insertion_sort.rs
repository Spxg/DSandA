fn insertion_sort(vec: &mut Vec<i32>) {
    for i in 1..vec.len() {
        let value = vec[i];
        let mut index = i as i32 - 1;
        while index >= 0 && vec[index as usize] > value {
            vec[index as usize + 1] = vec[index as usize];
            index -= 1;
        }
        vec[(index + 1) as usize] = value;
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).expect("read error");
    let mut numbers = buf.trim().split(" ").into_iter()
                    .map(|num| num.parse::<i32>().expect("parse error"))
                    .collect::<Vec<i32>>();
    insertion_sort(&mut numbers);
    println!("{:?}", numbers);
}