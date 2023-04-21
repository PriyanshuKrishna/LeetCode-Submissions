ans[top][i]=temp[x++];
​
}
top++;
for (int i=top;i<=bottom && left<=right;i++){
ans[i][right]=temp[x++];
}
right--;
for (int i=right;i>=left && top<=bottom;i--){
ans[bottom][i]=temp[x++];
}
bottom--;
for (int i=bottom;i>=top && left<=right;i--){
ans[i][left]=temp[x++];
}
left++;
}
for(int i=0;i<m;i++){
for(int j=0;j<m;j++){
cout<<ans[i][j]<<" ";
}cout<<endl;
}
return result;
}
};