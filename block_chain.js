const fs = require('fs');
const merkle = require('merkle');

class Block{
    constructor(header, body){
        this.header = header;
        this.body = body;
    }
}

class Block_header{
    constructor(version, previousBlockHash, timestamp, merkleRoot, bit, nonce){
        this.version = version;
        this.previousBlockHash = previousBlockHash;
        this.timestamp = timestamp;
        this.merkleRoot = merkleRoot;
        this.bit = bit;
        this.nonce = nonce;
    }
}

let getVersion = () => {
    const package = fs.readFileSync("package.json");
    return JSON.parse(package).version;
};

let createGenesisBlock = () => {
    const version = getVersion();
    const previousBlockHash = '0'.repeat(64);
    const timestamp = parseInt(Date.now()/1000);
    const body = ['hello block'];
    const tree = merkle('sha256').sync(body);
    const merkleRoot = tree.root() || '0'.repeat(64);
    const bit = 0;
    const nonce = 0;

    console.log(`version : ${version}, timestamp : ${timestamp}, body: ${body}`);
	console.log(`previousBlockHash : ${previousBlockHash}`);
	console.log(`tree : ${tree}`);
	console.log(`merkleRoot : ${merkleRoot.toString('hex')}`);

    const header = new Block_header(version, previousBlockHash, timestamp, merkleRoot, bit, nonce);
	return new Block(header, body);
};

const block_1 = createGenesisBlock();
console.log(block_1);
console.log('_________________________________________');
const block_2 = createGenesisBlock();
console.log(block_2);

/* sorting 부분.
    4장 연습문제
    hazard 개념 용어 설명  
*/