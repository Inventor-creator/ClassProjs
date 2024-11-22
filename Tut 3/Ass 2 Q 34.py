employeeRecords = [{"name": 'mukhul', 'age' : 9 , 'salary' : 10 , 'department': 'IT'}, 
                   {"name": 'Neha', 'age' : 20 , 'salary' : 12 , 'department': 'IT'},
                   {"name": 'Sahil', 'age' : 20 , 'salary' : 15 , 'department': 'IT'},
                   {"name": 'Saina', 'age' : 21 , 'salary' : 35 , 'department': 'CS'},
                   {"name": 'Ishaan', 'age' : 20 , 'salary' : 20 , 'department': 'CS'}]

#1

def totalSalaryByDepartment(data):
    totalSalary = {}
    count = {}
    final = {}
    for i in data:
        if i['department'] in totalSalary:
            count[i['department'] ] += 1
            totalSalary[i['department']] += i['salary'] 
        else:
            count[i['department'] ] = 1
            totalSalary[i['department']] = i['salary'] 
    
    for i in totalSalary:
        final[i] = totalSalary[i] / count[i]
    return final
    
print("Avg Salaries by departments are: " ,totalSalaryByDepartment(employeeRecords)) 

def departmentWhighestSalary(data):
    totalSalary = {}
    
    for i in data:
        if i['department'] in totalSalary:
            
            totalSalary[i['department']] += i['salary'] 
        else:
            
            totalSalary[i['department']] = i['salary'] 
    
    maxi = 0
    department = ''
    for i in totalSalary:
        if totalSalary[i] > maxi:
            maxi = totalSalary[i]
            department = i

    return department

print("The department w the highest salary is: ",departmentWhighestSalary(employeeRecords))

def youngestEmployee(data):
    minAge = 1000000
    name = ''
    
    for i in data:
        if i['age'] < minAge:
            minAge = i['age']
            name = i['name']
    
    return name

print("The youngest employee in the company is " , youngestEmployee(employeeRecords))