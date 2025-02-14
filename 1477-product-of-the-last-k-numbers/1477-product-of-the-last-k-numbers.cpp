class ProductOfNumbers {
    private:
    std::vector<int> prefixProducts;
    int zeroIndex;  // Tracks last index where 0 was encountered
public:
    ProductOfNumbers() {
         prefixProducts.push_back(1);  // Initialize with 1 for multiplication
        zeroIndex = -1; 
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts.clear();
            prefixProducts.push_back(1);  // Reset prefix products
            zeroIndex = prefixProducts.size(); // Track last zero position
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefixProducts.size()) { // If k includes a 0, return 0
            return 0;
        }
        return prefixProducts.back() / prefixProducts[prefixProducts.size()- k-1]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */