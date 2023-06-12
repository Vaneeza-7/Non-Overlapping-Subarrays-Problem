#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

bool find_subarrays(vector<vector<string>> groups, vector<string> nums)
{
    bool flag = true;
    vector<bool>used(nums.size(), false);

    for (int i = 0; i < groups.size(); i++)  //for each group in groups
    {
        bool group_found = false;
        int group_size = groups[i].size();  //take size of group
        for (int j = 0; j < nums.size() - group_size + 1; j++)//total number of ingredients in nums- number of ingredients in group 
        {
            if (!used[j]){
                bool num_found = true;
            for (int k = 0; k < group_size; k++)
            {

                bool element_found = false;
                for (int l = 0; l < group_size; l++) {
                    if (nums[j + k] == groups[i][l] && !used[j+k]) {
                        element_found = true;
                        break;
                    }
                }
                if (!element_found) {
                    num_found = false;
                    break;
                }

            }

            if (num_found)
            {
                group_found = true;
                for (int k = 0; k < group_size; k++)
                {
                    used[j + k] = true;
                }
                
                // Break out of the loop so that we don't consider this group again
                break;
            }
               }//used loop
        }

        if (group_found)
        {
            
            cout << "Group " << i + 1 << " found in nums." << endl;
        }
        else
        {
            flag = false;
            cout << "Group " << i + 1 << " not found in nums." << endl;
        }
    }
    if (flag) {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return flag;
}

int main()
{
    vector<vector<string>> groups = { {"lettuce", "tomato", "cucumber"},
    {"pasta", "tomato", "chicken"},
    {"flour", "sugar", "eggs", "milk"},
    {"milk", "sugar", "custard"} };
    
    //Test case 1: true
    vector<string> nums1 = { "onions", "potatoes", "pasta",
        "lettuce", "tomato", "cucumber",
        "mangoes","pasta", "tomato",
        "chicken","bananas", "apples",
        "flour", "sugar", "eggs",
        "milk", "milk","custard", "sugar" };

   // Test case 2: true
    vector<string> nums2 = {"pasta", "tomato", "chicken", "onion",
        "lettuce", "cucumber", "tomato",
        "potatoes", "milk", "sugar", "custard", 
        "bananas", "flour", "sugar", 
        "eggs", "milk", "mangoes"};

   //Test case 3: false
    vector<string> nums3 = { "pasta", "tomato", "chicken", "lettuce", "cucumber",
        "milk", "sugar", "custard",
        "flour", "sugar", "eggs", "milk", "tomato" };

    //Test case 4: false
    vector<string> nums4 = { "pasta", "chicken", "tomato", "lettuce",
           "cucumber", "milk", "sugar", "custard",
           "flour", "sugar", "eggs", "milk" };
    //Test case 5: false
    vector<string> nums5 = {"lettuce", "tomato", "cucumber", 
        "pasta", "tomato", "chicken",
        "flour", "sugar", "eggs", "milk", "milk", "sugar" };

        cout << "Test Case 1\n";
        find_subarrays(groups, nums1);
        cout << "Test Case 2\n";
        find_subarrays(groups, nums2);       
        cout << "Test Case 3\n";
        find_subarrays(groups, nums3);
        cout << "Test Case 4\n";
        find_subarrays(groups, nums4);
        cout << "Test Case 5\n";
        find_subarrays(groups, nums5);

    // Test case 6:true
        vector<vector<string>> groups2 = { {"avocado", "tomato", "onion", "lime"},
        {"black beans", "rice", "corn", "cilantro"},
        {"tortilla chips", "cheese", "jalapeno", "salsa"},
        {"sour cream", "chicken", "bell pepper", "onion"},
        {"flour", "butter", "sugar", "eggs","vanilla"} };

        vector<string>   nums6 = { "avocado", "tomato", "onion", "lime", "d",
          "tomato", "onion", "lime", "black beans", "rice",
         "corn", "cilantro", "black beans", "a", "tortilla chips",
         "jalapeno", "cheese", "salsa", "black beans", "chicken", "bell pepper", "sour cream",
          "onion", "sugar", "butter", "flour", "sugar", "vanilla", "eggs", "extra" };

    //Test case 7:false
        vector<vector<string>> groups3 = { {"broccoli", "cauliflower", "carrot", "garlic"},
        {"potato", "cheese", "milk", "butter"},
        {"chicken", "rosemary", "lemon", "olive oil"},
        {"flour", "sugar", "cocoa", "butter", "baking powder", "eggs"},
        {"cream", "vanilla", "sugar", "egg yolks"} };

        vector<string>nums7 = { "broccoli", "cauliflower", "carrot", "garlic", "potato", "cheese",
            "milk", "butter", "flour", "sugar", "cocoa", "baking powder", "eggs",
            "chicken", "rosemary", "lemon", "cream", "vanilla", "sugar", "egg yolks" };
      
        
      //TestCase8:false
        vector<vector<string>> groups4 = { {"avocado", "tomato", "onion", "lime"},
                {"black beans", "rice", "corn", "cilantro"},
                {"tortilla chips", "cheese", "jalapeno", "salsa"},
                {"sour cream", "chicken", "bell pepper", "onion"},
                {"flour", "butter", "sugar", "eggs", "vanilla"},
                {"cinnamon", "nutmeg", "sugar", "eggs", "milk", "vanilla"},
                {"spinach", "feta", "olive oil", "garlic"},
                {"banana", "oats", "honey", "milk"},
                {"beef", "onion", "garlic", "carrot", "potato"} };

        vector<string> nums8 = {"onion", "avocado", "lime", "tomato",
                "rice", "corn", "black beans", "cilantro", 
                "salsa", "jalapeno", "cheese", 
                "tortilla chips", "salsa", "sour cream", "onion",
                "bell pepper", "chicken", "flour", "sugar",
                "eggs", "butter", "vanilla", "banana", "oats",
                "honey", "milk", "beef", "onion", "garlic", "carrot", "corn"};
     
        //Test case9: false
        vector<string> nums9 = { "avocado", "tomato", "lime", "onion", "sour cream",
                 "chicken", "bell pepper", "black beans", "rice",
                 "corn", "cilantro", "tortilla chips", "cheese",
                 "jalapeno", "salsa", "flour", "butter", "sugar",
                 "eggs", "vanilla", "cinnamon", "nutmeg", "sugar", "eggs",
                 "milk", "vanilla", "spinach", "feta", "olive oil", "garlic",
                 "banana", "oats", "honey", "milk", "beef",
                 "onion", "garlic", "carrot", "potato", "tomato" };
        
        cout << "Test Case 6\n";
        find_subarrays(groups2, nums6);
        cout << "Test Case 7\n";
        find_subarrays(groups3, nums7);
        cout << "Test Case 8\n";
        find_subarrays(groups4, nums8);
        cout << "Test Case 9\n";
        find_subarrays(groups4, nums9);

}


