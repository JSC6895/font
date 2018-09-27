webpack.config.js
```javascript
var path = require("path");

module.exports = {
  entry:"./app/main.js",
  output:{
    path: path.resolve(__dirname,"dist"),
    filename:"bundle.js"
  },
  watch:true
}
```
