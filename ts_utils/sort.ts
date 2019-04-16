const swap = (arr: number[], i:number, j:number) => {
	const tmp = arr[i]
	arr[i] = arr[j]
	arr[j] = tmp
}

const generateArr = (len: number = 20) => {
	let arr = Array(len)
	for(let i = 0; i < len; i++) {
		arr[i] = Math.floor(Math.random() * 10000)
	}
	return arr
}

const pivot = (arr: number[], start: number, end: number): number => {
	if((end - start) < 1) return start
	let pivotVal = arr[start]
	let swapIdx = start
	for(let i = start+1; i <= end; i++) {
		if(pivotVal > arr[i]) {
			swapIdx++
			swap(arr, i, swapIdx)
		}
	}
	swap(arr, swapIdx, start)

	return swapIdx
}

const quicksort = (arr: number[], start: number = 0, end: number = arr.length) => {
	if(arr.length < 2) return arr
	if((end - start) < 1) return start

	let mid = pivot(arr, start, end)
	quicksort(arr, start, mid - 1)
	quicksort(arr, mid+1, end)
}

let array = generateArr()
console.log(array.join('/'))
quicksort(array)
console.log(array.join('/'))
