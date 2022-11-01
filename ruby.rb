carrinho = [
  {
    "id" => 1,
    "produto" => "iphone",
    "preco" => 499
  },
  {
    "id" => 2,
    "produto" => "kindle",
    "preco" => 179
  },
  {
    "id" => 3,
    "produto" => "macbook",
    "preco" => 1199
  }
]

carrinho2 = [
  {
    "id" => 1,
    "produto" => "iphone",
    "preco" => 499
  },
  {
    "id" => 2,
    "produto" => "kindle",
    "preco" => 179
  }
]

thread1 = Thread.new{
  precoCarrinho = carrinho.map{ |produto| produto["preco"] }.sum
  puts "Preco total do carrinho1: #{precoCarrinho}"
} 
thread2 = Thread.new{
  precoCarrinho = carrinho2.map{ |produto| produto["preco"] }.sum
  puts "Preco total do carrinho2: #{precoCarrinho}"
}

threads = [thread1, thread2]

threads.each{ |thr| thr.join }

