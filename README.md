# DAA-ASSIGNMENT-2
## Problem Statement:  
## Implement the optimal binary search tree algorithm and demonstrate three test cases.

Here, We are creating a Phone Book which have name,contact number and frequency(how many times a particular contact number is called) array.Using these information, we are creating a Tree that will produce minimum cost.  

Here, I have added features like call someone, create new contact.  
When we call someone, the name/number is searched in the OBST and the level is returned in which the name/number is found.Also, this operation increases the frequenc of that particular person and a new OBST is created with minimum cost.  
When we create a new contact, name and number is taken and added to the respective arrays. Then,a new OBST is created with frequency of newly added contact as 1.  


With 'n' different nodes, we can create <img width="50" alt="image" src="https://user-images.githubusercontent.com/97373985/203815813-cf0d34e1-b75c-45f8-80b0-4cb66c808d6d.png"> different trees.  
Thus, we need to find the Tree whose cost can be minimum and this can be done with Optimal Binary Search Tree.

#### **Printing the OBST with already present information.**  
<img width="234" alt="image" src="https://user-images.githubusercontent.com/97373985/203821891-dc7aceeb-f97f-4c46-83f2-b9ded9f03762.png">  
<img width="318" alt="image" src="https://user-images.githubusercontent.com/97373985/203825291-71d3c531-0bbd-4935-b462-4757d10f6ce9.png">


### Calling Operation  
#### **Test Case 1: Name is found and frequency is incremented. OBST updated.**  
<img width="226" alt="image" src="https://user-images.githubusercontent.com/97373985/203822161-374a226c-d809-49b3-a654-400965257b61.png">

#### **Test Case 2: Name is not found.**  
<img width="222" alt="image" src="https://user-images.githubusercontent.com/97373985/203822234-3cd9c239-ca7a-4b87-b2cd-22099e7a6a61.png">

#### **Test Case 3: Number is found and Frequency is incremented. OBST updated.**   
<img width="335" alt="image" src="https://user-images.githubusercontent.com/97373985/203822367-bc289831-23da-4a2e-a74e-d92b29c7bfc6.png">

#### **Test Case 4: Number not found.**  
<img width="216" alt="image" src="https://user-images.githubusercontent.com/97373985/203822583-18ca51da-89ff-496f-9e01-1890b27acc5e.png">

#### **Printing the updated OBST and cost,order matrix**  
<img width="256" alt="image" src="https://user-images.githubusercontent.com/97373985/203824486-0707fd4e-4e6b-45cf-9e26-0ce18b170064.png">
<img width="336" alt="image" src="https://user-images.githubusercontent.com/97373985/203824858-b505af51-911f-493a-97de-125cd8b2f3c4.png">  

#### **Creating new contact**  
<img width="373" alt="image" src="https://user-images.githubusercontent.com/97373985/203828721-4fdc9852-f90d-4c59-ae3d-3becd6b3d100.png">  
<img width="304" alt="image" src="https://user-images.githubusercontent.com/97373985/203828238-6191ed42-51b3-4274-8aa1-97cb2f629071.png">  
<img width="332" alt="image" src="https://user-images.githubusercontent.com/97373985/203828320-00c77bd4-ac1b-4771-92fe-aa477d1ac31c.png">  



