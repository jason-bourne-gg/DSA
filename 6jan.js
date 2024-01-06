var subset = function (nums) {
    let result = [[]];

    // index, keeps tracks of nums number,currArr build subsets with that 
    function recurse (index, currArr) {
        for (let i=index; i<nums.length; i++){
            currArr.push(nums[i])
            result.push([...currArr])
            recurse(i+1,currArr)
            currArr.pop()

        }
    }
    recurse (0,[])
    return result
}

// test case 1
const nums = [1,2,3]
console.log(subset(nums))

// expeected output = [1], [1,2], [], .....[1,2,3]
