class HouseKeeper {
    constructor(name, mobile, start) {
        this.name = name;
        this.mobile = mobile;
        this.start = start;
        this.cleanRoom = function() {
            clean();
        }
    }
}

function clean() {
    alert('Cleaning in progress!');
}
// let houseKeeper = {
//     name: "Angel",
//     mobile: "8786817978",
//     start: "19/09/2020"
// }

let houseKeeper = new HouseKeeper("Angel", "8786817978", "19/09/2020");
houseKeeper.cleanRoom();