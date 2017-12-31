'use strict'

/*
	寄生组合式继承
 */
function object(0){
	function F(){}
	F.ptototype = o;
	return new F();
}

function inheritPrototype(Person,Mother){
	var prototype = object(Mother.prototype);
	prototype.constructor = Person;
	Person.prototype = prototype;
}

function Mother(age){
	this.age = age;
	this.hobby = ['running','football']
}

function Person(name,age){
	Mother.call(this,age);
	this.name = name;
}

inheritPrototype(Person,Mother);

Person.prototype.showName = function(){
	console.log(this.name);
}

var p1 = new Perosn('Jack',20);
p1.hobby.push('basketball');

var p2 = new Person('Mark',23);