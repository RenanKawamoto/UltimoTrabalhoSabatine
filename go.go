package main

import "fmt"
import "time" 

type produto struct {
	id      int
	produto string
	preco   float32
}

func criarListaDePrecos(produtos []produto) []float32 {
	var lista []float32
	for i := 0; i < len(produtos); i++ {
		lista = append(lista, produtos[i].preco)
	}
	return lista
}

func sumPrecos(precos []float32, nome string) {
	var soma float32 = 0
	for i := 0; i < len(precos); i++ {
    time.Sleep(100 * time.Millisecond)
		soma += precos[i]
    fmt.Println(nome, "somando valor no atual", soma)
	}
  fmt.Println("Resultado final da soma do", nome, soma)
}

func main() {
	iphone := produto{
		1,
		"IPhone",
		499,
	}

	kindle := produto{
		2,
		"Kindle",
		179,
	}

	macbook := produto{
		3,
		"Macbook Pro",
		1199,
	}

	carrinho := []produto{iphone, kindle, macbook}
  carrinho2 := []produto{iphone, macbook, kindle, macbook}
  
	carrinhoPrecos := criarListaDePrecos(carrinho)
  carrinhoPrecos2 := criarListaDePrecos(carrinho2)
  
	go sumPrecos(carrinhoPrecos, "Carrinho-1:")
  sumPrecos(carrinhoPrecos2, "Carrinho-2:")

}
