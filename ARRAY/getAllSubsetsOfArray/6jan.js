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
// console.log(subset(nums))

// expeected output = [1], [1,2], [], .....[1,2,3]


// Alternate Solution

  function getAllSubsets(arr) {
  const result = [];

  function generateSubsets(currentSubset, index) {
    if (index === arr.length) {
    // console.log([...currentSubset])
      result.push([...currentSubset]);
      return;
    }

    // Exclude the element at the current index
    generateSubsets(currentSubset, index + 1);

    // Include the element at the current index
    currentSubset.push(arr[index]);
    generateSubsets(currentSubset, index + 1);

    // Backtrack to restore the original state for the next iteration
    currentSubset.pop();
  }

  generateSubsets([], 0);

  return result;
}

// Example usage:
const inputArray = [1, 2, 3];
const subsets = getAllSubsets(inputArray);

console.log(subsets);