const a = [3, 2, 2, 3];
let val = 3;
const newarr = a.map(function (number, index) {
      if (number != val) {
            return index;
      }
});
console.log(newarr);