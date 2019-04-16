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

function on(num: number, position: number): number {
	const mask = 1 << position;
	return num | mask;
}

function off(num: number, position: number): number {
	const mask = ~(1 << position);
	return num & mask;
}

function flip(num: number, position: number): number {
	const mask = 1 << position;
	return num ^ mask;
}

function isEven(num) {
	let mask = 1;
	return ((mask & num) === 0) // 右端が0
}

function addOne(num) {
	return -(~num);
}

function has(num, position) {
	let mask = 1 << position;
	return (mask & num) > 0;
}

function powerOfTwo(num) {
	// 1を1つだけもつ
	return (num & (num-1)) === 0;
}

function findRightmostSetbit(num) {
	// 1. 右端の1をunsetし
	let unset = num & (num-1);
	// 2. もとの値とxor ... rightmost setbitの1だけ1になる
	let n = num ^ unset;
	// 3. 右端からみていって, 最初に1に到達擦るまで続ける
	let pos = 0;
	while(n > 0) {
		pos++;
		n = n >> 1;
	}
	return pos;
}

