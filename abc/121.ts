function calc(num) {
	if(num <= 0) return num;
	switch(num%4) {
		case 0:
			return num;
		case 1:
			return toDecimal(xorBigInt(numToBitarr(num),numToBitarr(num-1)));
		case 2:
			let tmp = toDecimal(xorBigInt(numToBitarr(num),numToBitarr(num-1)));
			return toDecimal(xorBigInt(numToBitarr(tmp), numToBitarr(num-2)));
		case 3:
			return 0;
	}
}

// TODO: 汎用化
function numToBitarr(num) {
	return toBinary(num).split('').map((num) => (Number(num)))
}

function toBinary(num) {
	return Number(num).toString(2)
}

function toDecimal(bitarr) {
	return parseInt(bitarr.join(''), 2);
}

function xorBigInt(a, b) {
	a = [...a].reverse();
	b = [...b].reverse();
	let result = []
	for(let i = 0; i < Math.min(a.length, b.length); i++) {
		result[i] = a[i] ^ b[i];
	}

	if(result.length < a.length) {
		for(let i = result.length; i < a.length; i++) {
			result[i] = a[i];
		}
	}

	if(result.length < b.length) {
		for(let i = result.length; i < b.length; i++) {
			result[i] = b[i];
		}
	}

	return result.reverse()
}



function Main(input) {
	let ab = input.split(' ').map((num) => (parseInt(num, 10)));
	let a = ab[0];
	let b = ab[1];

	if(a === b) {
		console.log(a);
		return
	}

	// unsigned integer扱いになる
	let result = xorBigInt(numToBitarr(calc(b)), numToBitarr(calc(a-1)));
	result = parseInt(result.join(''), 2);
	console.log(result);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
