###
```bash
cnpm install --save-dev babel-loader babel-core #
cnpm install --save-dev babel-preset-env babel-preset-react
```


####webpack.config.js
```javascript
var path = require("path");

module.exports = {
  entry:"./app/main.js",
  output:{
    path: path.resolve(__dirname,"dist"),
    filename:"bundle.js"
  },
  module:{
    rulees:[{
      test:/\.js$/,
      use:[{
        loader:"bable-loader",
        options:{
          presets:["env","react"]
      }]
    }]
  }
  watch:true
}
```
