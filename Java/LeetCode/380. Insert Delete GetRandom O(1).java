class RandomizedSet {
    ArrayList<Integer> arr;
    Map<Integer,Integer> map;

    

    public RandomizedSet() {
        map=new HashMap<Integer,Integer>();
        arr =new ArrayList<Integer>();
        
    }
    
    public boolean insert(int val) 
    {
        if(map.containsKey(val))
            return false;
        map.put(val,arr.size());
        arr.add(val);
        return true;
        
    }
    
    public boolean remove(int val) 
    {
        if(map.containsKey(val))
        {
            int index=map.get(val);
            arr.set(index,arr.get(arr.size()-1));
            map.put(arr.get(index),index);
            arr.remove(arr.size()-1);
            map.remove(val);
            return true;
        }
        return false;
        
    }
    
    public int getRandom() 
    {
        Random rand = new Random();
        int index=rand.nextInt(arr.size());
        return arr.get(index);
        
        
    }
}