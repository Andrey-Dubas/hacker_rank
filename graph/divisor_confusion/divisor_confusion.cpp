#include <cmath>                                                                                              
                                                                                                              
                                                                                                              
std::vector<int> eratosphen(int max)                                                                          
{                                                                                                             
    std::vector<int> result;                                                                                  
    result.push_back(2);                                                                                      
                                                                                                              
    for (int i = 3; i < sqrt(max); ++i)                                                                       
    {                                                                                                         
                                                                                                              
        bool found = true;                                                                                    
        for (int j = 0; j < result.size(); ++j)                                                               
        {                                                                                                     
            if (i % result[j] == 0)                                                                           
            {                                                                                                 
                found = false;                                                                                
                break;                                                                                        
            }                                                                                                 
        }                                                                                                     
                                                                                                              
        if (found)                                                                                            
        {                                                                                                        
            result.push_back(i);                                                                                 
        }                                                                                                        
    }                                                                                                            
    return result;                                                                                               
}


