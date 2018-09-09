将rectangle.js和round.js直放入一个名为jihe的文件夹中
在文件夹同级的目录下新建一个app.js文件，文件中引用jihe目录下index.js文件（引用rectangle.js和round.js暴露的方法,引用及暴露)时
```javascript
var jihe = require("./jihe"); //不需加index.js,如果将jihe文件夹放入node_module文件夹中则不需加“./”
console.log(jihe.rectangle.area(1,2));
```
