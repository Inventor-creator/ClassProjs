def process_grocery_list(grocery_list):
    idk = grocery_list
    l = 0
    r = 1
    if not idk:
        return []
    
    for i in range(len(idk)):
        
        while r < len(idk):
            try:
                if not idk[l]['quantity'] or not idk[r]['quantity'] or not idk[l]['price'] or not idk[r]['price'] or not idk[l] or not idk[r]:
                    continue
            except:
                continue
                
            try: 
                if int(idk[l]['quantity']) * int(idk[l]['price']) < int(idk[r]['quantity']) * int(idk[r]['price']):
                    temp = idk[r]
                    idk[r] = idk[l]
                    idk[l] = temp   
                elif int(idk[l]['quantity']) * int(idk[l]['price']) == int(idk[r]['quantity']) * int(idk[r]['price']): 
                    
                    nameSort = sorted([str(idk[l]['name']) , str(idk[r]['name'])])
                    
                    if nameSort[0] != idk[l]['name']:
                        temp = idk[r]
                        idk[r] = idk[l]
                        idk[l] = temp 
            except:
                continue
                
            l += 1
            r += 1
            print(idk , '\n')
    grocery_list = idk
    return grocery_list

grocery_list =  [
    {'name': 'xylophone candy', 'quantity': 10, 'price': 1},
    {'name': 'yak cheese', 'quantity': 4, 'price': 12},
    {'name': 'zucchini', 'quantity': 5, 'price': 2},
    {'name': 'artichokes', 'quantity': 6, 'price': 4},
    {'name': 'blueberries', 'quantity': 8, 'price': 3},
    {'name': 'crab apples', 'quantity': 7, 'price': 1}
]

process_grocery_list(grocery_list)
