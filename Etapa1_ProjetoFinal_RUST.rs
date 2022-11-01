use std::thread;

// Tipo Produto
struct Produto {
    id: i32,
    produto: String,
    preco: f32
}

// Função que o Thread roda
fn calcular_carrinho(produtos: Vec<Produto>, numThread: i32)
{
    println!("Produtos do Thread |{numThread}|:");
    
    for index in 0..produtos.len() {
        println!("    - {} - R$ {}", produtos[index].produto, produtos[index].preco);
    }
    
    println!("Soma dos Preços:");
    let sum_precos: f32 = produtos.iter().map(|x| x.preco).sum();
    println!("R$ {sum_precos}");
}

fn main() {
    // Carrinho
    let produtos0 = vec![Produto{id: 1, produto: "Kindle".to_string(), preco: 179.0}];
    let produtos1 = vec![Produto{id: 1, produto: "Kindle".to_string(), preco: 179.0}, Produto{id: 2, produto: "IPhone".to_string(), preco: 499.0}];   
    let produtos2 = vec![Produto{id: 1, produto: "Kindle".to_string(), preco: 179.0}, Produto{id: 2, produto: "IPhone".to_string(), preco: 499.0}, Produto{id: 3, produto: "Macbook Pro".to_string(), preco: 1199.0}];   
    let produtos3 = vec![Produto{id: 1, produto: "Kindle".to_string(), preco: 179.0}, Produto{id: 2, produto: "IPhone".to_string(), preco: 499.0}, Produto{id: 3, produto: "Macbook Pro".to_string(), preco: 1199.0}, Produto{id: 4, produto: "Apple Workstation".to_string(), preco: 10000.0}];
    
    // Criação dos Threads
    let t_produtos0 = thread::spawn( || {calcular_carrinho(produtos0, 1)});
    let t_produtos1 = thread::spawn( || {calcular_carrinho(produtos1, 2)});
    let t_produtos2 = thread::spawn( || {calcular_carrinho(produtos2, 3)});
    let t_produtos3 = thread::spawn( || {calcular_carrinho(produtos3, 4)});
    
    // Join dos Threads
    t_produtos0.join().unwrap();
    t_produtos1.join().unwrap();
    t_produtos2.join().unwrap();
    t_produtos3.join().unwrap();
}