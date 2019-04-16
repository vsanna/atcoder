class UnionFind {
	public data: { [key: string]: number|string }

	constructor(){
		this.data = {}
	}

	// add(name: string, parent: string|null)
	// root(name: string): string
	// unite(a:string, b:string)
	// same(a: string, b: string): boolean
	// size(a: string): number

	addNode(name: string, parent: string|null) {
		this.data[name] = parent || -1;
	}

	findRoot(name: string): string {
		const parent = this.data[name];
		if(typeof parent === 'string') return this.findRoot(parent);
		return name;
	}

	unite(from: string, to: string) {
		let rootFrom = this.findRoot(from);
		let rootTo = this.findRoot(to);
		(this.data[rootTo] as number) += this.data[rootFrom] as number;
		this.data[rootFrom] = rootTo;
	}

	same(a: string, b: string): boolean {
		return this.findRoot(a) === this.findRoot(b);
	}

	size(a: string): number {
		return this.data[this.findRoot(a)] as number;
	}
}