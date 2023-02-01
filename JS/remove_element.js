var N = 10;
var A = [];
for (var i = 1; i <= N; i++) {
      A.push(i);
}
var L = 3;
var S = 6;
var subarray = [];
var sum = 0;
var found = false;
for (var i = 0; i < A.length; i++) {
      subarray.push(A[i]);
      sum += A[i];
      if (subarray.length == L) {
            if (sum == S) {
                  found = true;
                  break;
            }
            sum -= subarray.shift();
      }
}
if (found) {
      console.log('Yes');
} else {
      console.log('No');
}