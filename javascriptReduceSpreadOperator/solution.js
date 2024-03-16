const arr = [
  { country: "India", export: 2000 },
  { country: "USA", export: 100 },
  { country: "India", export: 1000 },
];

const res = {};
for (let obj of arr) {
  if (!res[obj.country]) {
    res[obj.country] = 0;
  }
  res[obj.country] += obj.export;
}

const agg = arr.reduce((agg, curObj) => {
  if (!agg[curObj.country]) {
    agg[curObj.country] = 0;
  }
  return { ...agg, [curObj.country]: agg[curObj.country] + curObj.export };
}, {});
console.log(res);
console.log(agg);

let obj2 = { key1: "dasd", key2: "asfa" };
// obj2.key3 = "132"
let newKey = "key3";
obj2 = { ...obj2, [newKey]: "Weq" };
console.log(obj2);
