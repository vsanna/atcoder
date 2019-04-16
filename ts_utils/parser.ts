function strToArr(input: string): number[] {
	return input.split(' ').map((num) => (parseInt(num, 10)));
}
