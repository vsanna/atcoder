class PriorityQueue {
	constructor( private data: { name: string, weight: number }[] = []){}

	length(): number {
		return this.data.length
	}

	enqueue(name: string, weight: number) {
		this.data.push({name, weight})
		this.sort()
	}

	dequeue(): string {
		let head = this.data.shift()!
		this.sort()
		return head.name
	}

	sort() {
		this.data.sort((a, b) => {
			if(a.weight > b.weight) {
				return 1
			} else if (a.weight < b.weight) {
				return -1
			} else {
				return 0
			}
		})
	}
}

class Graph {
	constructor(
		/*
		{
			a: [{name: b, weight: 10}, {name: c, weight: 10}, {name: d, weight: 30}, {name: e, weight: 40}],
			b: [{name: f, weight: 10}, {name: c, weight: 10}, {name: d, weight: 30}, {name: e, weight: 40}],
		}
		*/
		private list: { [name: string]: { name: string, weight: number}[] } = {}
	){}

	// O(1)
	addNode(name: string){
		if(!this.list[name]) {
			this.list[name] = []
		}
	}

	// O(|E|)
	addEdge(from: string, to: string, weight: number) {
		if(!this.list[from]) {
			this.list[from] = []
		}
		let toEdge = this.list[from].find((edge) => (edge.name === to))
		if(!toEdge){
			this.list[from].push({ name: to, weight })
		}
	}

	// O(|V| + |E|)
	removeNode(name: string) {
		let names = Object.keys(this.list)
		for(let i = 0; i < names.length; i++) {
			this.list[names[i]] = this.list[names[i]].filter((node) => {
				return node.name !== name
			})
		}
		delete this.list[name]
	}
	// O(|V| + |E|)
	removeEdge(a: string, b: string) {
		this.list[a] = this.list[a].filter((node) => {
			return node.name !== b
		})
		this.list[b] = this.list[b].filter((node) => {
			return node.name !== a
		})
	}

	// startから辿れる先を列挙する: result.push(current)を返す
	// pathの有無を返す: goalとマッチすればtrueを返す
	// pathを返す: dijkstra使う
	traverseBFS(start: string): string[] {
		let visited: { [name: string]: boolean } = {}
		let remains: string[] = [start]
		let result = []

		while(remains.length > 0) {
			let current = remains.shift()!
			if (visited[current]) continue
			visited[current] = true
			result.push(current)
			for(let i = 0; i < this.list[current].length; i++) {
				let neighbor = this.list[current][i]	
				if(visited[neighbor.name]) continue
				remains.push(neighbor.name) 
			}
		}
		
		return result
	}

	traverseDFS(start: string): string[] {
		let remains = [start]
		let visited: {[name: string]: boolean} = {}
		let result = []
		while(remains.length > 0) {
			let current = remains.pop()!
			if (visited[current]) continue
			result.push(current)
			visited[current] = true
			for(let i = 0; i < this.list[current].length; i++) {
				let neighbor = this.list[current][i]
				if(visited[neighbor.name]) continue
				remains.push(neighbor.name)
			}
		}

		return result
	}

	hasPath(start: string, to: string): boolean {
		let achievables = this.traverseBFS(start)
		return achievables.indexOf(to) >= 0;
	}

	dijkstra(start: string, to: string): {path: string[]|null, distance: number|null} {
		let remains = new PriorityQueue()
		let previous: {[k:string]: string | null} = {}
		let visited: {[k:string]: boolean} = {}
		let distances: {[k: string]: number} = {}
		
		// 初期化
		remains.enqueue(start, 0)
		distances[start] = 0
		previous[start] = null

		while(remains.length() > 0) {
			let current = remains.dequeue()
			if(current === to) break
			if(visited[current]) continue
			visited[current] = true
			for(let i = 0; i < this.list[current].length; i++) {
				let neighbor = this.list[current][i]
				if(visited[neighbor.name]) continue
				if(!distances[neighbor.name] || distances[neighbor.name] > distances[current] + neighbor.weight) {
					previous[neighbor.name] = current
					distances[neighbor.name] = distances[current] + neighbor.weight
				}
				// NOTE: ここはdistanceを入れること
				remains.enqueue(neighbor.name, distances[neighbor.name])
			}
		}

		if(!previous[to]) {
			return { path: null, distance: null };
		}

		let path = []
		let current = to
		while(true) {
			path.push(current)
			if(previous[current] === null) break
			current = previous[current]!
		}
		return { path: path.reverse(), distance: distances[to] }
	}
}


let g = new Graph()
g.addNode('a')
g.addNode('b')
g.addNode('c')
g.addNode('d')
g.addNode('e')
g.addNode('f')
g.addEdge('a', 'b', 10)
g.addEdge('b', 'a', 10)
g.addEdge('a', 'c', 5)
g.addEdge('c', 'b', 20)
g.addEdge('d', 'b', 10)
g.addEdge('b', 'd', 34)
g.addEdge('d', 'g', 7)
g.addEdge('g', 'd', 90)
g.addEdge('d', 'e', 10)
g.addEdge('d', 'f', 15)
g.addEdge('f', 'e', 10)
console.log(g)
console.log(g.traverseBFS('a'))
console.log(g.traverseBFS('e'))
console.log(g.traverseBFS('f'))
console.log(g.traverseDFS('a'))
console.log(g.traverseDFS('e'))
console.log(g.traverseDFS('f'))
console.log(g.traverseDFS('d'))
console.log(g.dijkstra('d', 'a'))