function Door(ID = 1, isOpen = false, point = 0, element = "ID") {
    this.num = ID;
    this.isOpen = isOpen;
    this.point = point;
    this.element = document.getElementById(element);
}

let point = 0;
let leftClick = 10;
// Door.prototype.clicked = function () {
//     if (this.isOpen) {
//         point += this.point;
//         alert(point);
//     }
// }
Door.prototype.closeDoor = function () {
    this.isOpen = false;
    this.element.style.backgroundColor = "#000";
    this.element.innerHTML = "";
    this.update();
}
Door.prototype.update = function () {
    this.point = Math.floor(Math.random() * 3) + 7;
}
let gameOver = function () {
    alert("you got " + point + " points");
    point = 0;
    leftClick = 10;
    document.getElementById("leftClick").innerHTML = "leftClick: " + leftClick;
    document.getElementById("point").innerHTML = "Point: " + point;
    for (let i = 0; i < 3; i++)
    array[i].closeDoor();
}
let door1 = new Door(1, false, 10, "door1");
let door2 = new Door(2, false, 10, "door2");
let door3 = new Door(3, false, 10, "door3");
let array = [door1, door2, door3];
let clicked = function (door) {
    // console.log(door.num);
    leftClick--;
    document.getElementById("leftClick").innerHTML = "leftClick: " + leftClick;
    if (door.isOpen) {
        point += door.point;
        // console.log({ point });
        document.getElementById("point").innerHTML = "Point: " + point;
    }
    else {
        door.isOpen = true;
        door.element.innerHTML = door.point;
        door.element.style.backgroundColor = "#fff";
    }
    for (let i = 0; i < 3; i++) {
        if (array[i].num != door.num) {
            array[i].closeDoor();
        }
    }
    if (leftClick <= 0) {
        gameOver();
    }
}
function clicked1() {
    clicked(door1);
}

function clicked2() {
    clicked(door2);
}

function clicked3() {
    clicked(door3);
}
door1.element.onclick = clicked1;
door2.element.onclick = clicked2;
door3.element.onclick = clicked3;
gameOver();