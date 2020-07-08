use std::fmt;

#[derive(Debug)]
struct Cards {
    cards: Vec<Card>,
}

#[derive(Debug, Clone, Copy, Eq, PartialEq)]
struct Card {
    suit: char,
    value: u8,
}

impl Card {
    fn new(card: &mut String) -> Card {
        let value = card.pop().unwrap();
        let value = value.to_digit(10).unwrap() as u8;
        let suit = card.pop().unwrap();
        Card { suit, value }
    }
}

impl fmt::Display for Card {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}{}", self.suit, self.value)
    }
}

impl fmt::Display for Cards {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for card in &self.cards {
            write!(f, "{} ", card).unwrap()
        }
        fmt::Result::Ok(())
    }
}

fn bubble_sort(vec: &mut Vec<Card>) {
    for i in 0..vec.len() {
        for j in (i + 1)..vec.len() {
            if vec[i].value > vec[j].value {
                vec.swap(i, j);
            }
        }
    }
}

fn selection_sort(vec: &mut Vec<Card>) {
    for i in 0..(vec.len() - 1) {
        let mut min_index = i;
        for j in (i + 1)..vec.len() {
            if vec[j].value < vec[min_index].value {
                min_index = j;
            }
        }
        vec.swap(i, min_index)
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).expect("read error");
    let mut cards = buf
        .trim()
        .split(" ")
        .into_iter()
        .map(|data| {
            let mut t = data.to_string();
            Card::new(&mut t)
        })
        .collect::<Vec<Card>>();
    let mut cards_clone = cards.clone();

    bubble_sort(&mut cards);
    let b_cards = Cards { cards };

    selection_sort(&mut cards_clone);
    let s_cards = Cards { cards: cards_clone };

    println!("{}", b_cards);
    println!("Stable");
    println!("{}", s_cards);
    if b_cards.cards.eq(&s_cards.cards) {
        println!("Stable")
    } else {
        println!("Not Stable")
    }
}
