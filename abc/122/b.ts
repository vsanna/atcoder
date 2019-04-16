function Main(input: string) {
	// write code belog...

}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));



// utils

function strToArr(input: string): number[] {
	return input.split(' ').map((num) => (parseInt(num, 10)));
}
