package main

import (
	"fmt"
	"math/rand"

	"rsc.io/quote"
)

func main() {
	fmt.Println(randQuote())
}
func randQuote() string {
	random_number := rand.Intn(3)
	print("")
	switch random_number {
	case 0:
		return quote.Glass()
	case 1:
		return quote.Hello()
	case 2:
		return quote.Go()
	case 3:
		return quote.Opt()
	}
	return "this isn't possible"
}
