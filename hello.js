var addon = require('./build/Release/hello');

console.log(''+addon.foo({x:42,y:2})); // 'world'
