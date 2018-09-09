```javascript
var express = require("express");
var app = express();
var count = 0;
app.get("/",function(req,res,next){ //next用于放行
  res.send("查询");
  count++;
  next()
})
app.use(express.static("public")); //静态化一个文件夹

```
