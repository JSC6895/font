/*
	除了冻结对象还要冻结对象的属性
 */
var constantize = (obj) => {
	Object.freeze(obj);
	Object.keys(obj).forEach( (key,i) => {
		if(typeof obj[key] === 'object'){
			constantize(obj[key]);
		}
	});
};