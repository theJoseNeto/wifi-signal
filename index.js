const express = require('express');
const cors = require("cors");
const app = express();
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use(cors());

const frequence = app.post("/frequence", (req, res) => {

    const wifiValues = Math.abs(req.body.rssi); 
    

});

app.listen(3333, () => console.log("server is running"));


