 for (int i = n / 2 ; i > 0;i--){
        heapify(arr, n, i);
    }   

    for (int i=1;i< n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;