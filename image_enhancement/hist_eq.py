import cv2
import numpy as np
from matplotlib import pyplot as plt
 
img = cv2.imread('sid.jpeg',0) 
hist,bins = np.histogram(img.flatten(),256,[0,256])

equ = cv2.equalizeHist(img)
res = np.hstack((img,equ)) #stacking images side-by-side
cv2.imwrite('res.png',res)
     
#clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
#cl1 = clahe.apply(img)
#cv2.imwrite('clahe_2.jpg',cl1)
cdf = hist.cumsum()
cdf_normalized = cdf * hist.max()/ cdf.max()
    
plt.plot(cdf_normalized, color = 'b')
plt.hist(img.flatten(),256,[0,256], color = 'r')
plt.xlim([0,256])
plt.legend(('cdf','histogram'), loc = 'upper left')
plt.show()

