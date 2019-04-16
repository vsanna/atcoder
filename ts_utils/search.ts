function binarysearch(arr: number[], target: number): boolean {

	function helper(array: number[], start:number = 0, end:number = array.length-1) {
		if(start === end) return array[start] === target;

		let mididx = Math.floor(((start + end) / 2));
		if(array[mididx] === target) return true;

		if(array[mididx] > target) {
			return helper(array, start, mididx);
		} else {
			return helper(array, mididx+1, end);	
		}
	}

	return helper(arr);
}


let a = [1, 2, 3, 4, 5]
let b = [1, 2, 3, 4, 5, 6]

console.log(binarysearch(a, 1))
console.log(binarysearch(a, 2))
console.log(binarysearch(a, 3))
console.log(binarysearch(a, 4))
console.log(binarysearch(a, 5))
console.log(binarysearch(a, 2.5))
console.log(binarysearch(a, -1))
console.log(binarysearch(a, 7))

console.log(binarysearch(b, 1))
console.log(binarysearch(b, 2))
console.log(binarysearch(b, 3))
console.log(binarysearch(b, 4))
console.log(binarysearch(b, 5))
console.log(binarysearch(b, 6))
console.log(binarysearch(b, 2.5))
console.log(binarysearch(b, -1))
console.log(binarysearch(b, 7))

