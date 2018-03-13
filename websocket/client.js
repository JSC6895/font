/*
向8080端口发送WebSocket连接，连接建立后打印日志，同时向服务端发送消息，接受到来自服务端的消息后，同样打印日志
 */
var ws = new WebSocket('ws://localhost:8080');
ws.onopen = function(){
	console.log('ws onopen');
	ws.send('from client:hello');

};
ws.onmessage = function(e){
	console.log('ws onmessage');
	consoel.log('from server:' + e.data);
};
