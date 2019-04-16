class Graph {
	public map: {} = {}
	constructor(){
		this.map = {}
	}

	addNode(name) {
		if(!this.map[name]) {
			this.map[name] = []
		}
	}

	addEdge(from, to) {
		if(this.map[from].indexOf(to) < 0) this.map[from].push(to)
		if(this.map[to].indexOf(from) < 0) this.map[to].push(from)
	}

	removeEdge(from, to) {
		this.map[from] = this.map[from].filter((toNode) => (toNode !== to))
		this.map[to] = this.map[to].filter((toNode) => (toNode !== from))
	}

	canReach(start) {
		let remains = [start];
		let visited = {};
		let result = [];
		while(remains.length) {
			let current = remains.shift();
			if(visited[current]) continue;
			visited[current] = true;
			result.push(current);
			for(let i = 0; i < this.map[current].length; i++) {
				let neighbor = this.map[current][i];
				if(visited[neighbor]) continue;
				remains.push(neighbor);
			}
		}
		return result;
	}

	// BFSで経路探す
	hasPath(start, goal) {
		let remains = [start];
		let visited = {};
		while(remains.length > 0) {
			let current = remains.shift();
			if(current === goal) return true;
			if(visited[current]) continue;
			visited[current] = true;
			for(let i = 0; i < this.map[current].length; i++) {
				let neighbor = this.map[current][i];
				if(visited[neighbor]) continue;
				remains.push(neighbor);
			}
		}
		return false;
	}
}

function Main(input) {
	let inputs = input.split("\n");
	let stats = inputs[0].split(' ').map((n) => (parseInt(n, 10)));
	let n = stats[0];
	let m = stats[1];
	
	let graph = new Graph();
	for(let i = 1; i <= n; i++) {
		graph.addNode(i);
	}

	let edges = [];
	for(let i = 0; i < m; i++) {
		let edge = inputs[i + 1].split(' ').map((n) => (parseInt(n, 10)));
		edges.push(edge);
		graph.addEdge(edge[0], edge[1]);
	}

	let score = 0;

	for(let i = 0; i < m; i++) {
		let edge = edges[i];
		graph.removeEdge(edge[0], edge[1]);
		if(!graph.hasPath(edge[0], edge[1])) {
			let leftsize = graph.canReach(edge[0]).length;
			let rightsize = graph.canReach(edge[1]).length;
			score += leftsize * rightsize;
		}
		console.log(score);
	}
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
