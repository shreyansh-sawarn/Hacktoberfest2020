import cv2
import numpy as np
import math

filename='C:/image_bw.png'
img = cv2.imread(filename, cv2.IMREAD_GRAYSCALE)
cv2.namedWindow('main')
cv2.imshow('main', img)
cv2.waitKey(0)

cross = np.array([[0, 1, 0], [1, 1, 1], [0, 1, 0]])

def dilation(image):
    dilated = np.zeros_like(image)

    for i in range(image.shape[1]):
        for j in range(image.shape[0]):
            if (image[j,i] == 255):
                dilated[j,i] = 255
                dilated[j-1,i] = 255
                dilated[j,i-1] = 255
                dilated[j+1,i] = 255
                dilated[j,i+1] = 255
    return dilated
dil=dilation(img)
cv2.namedWindow('main1')
cv2.imshow('main1', dil)
cv2.waitKey(0)

def erosion(image):
    eroded = np.zeros_like(image)
    #cv2.namedWindow('main3')
    #cv2.imshow('main3', eroded)
    #cv2.waitKey(0)
    for i in range(image.shape[1]):
        for j in range(image.shape[0]):
            if (image[j,i] == 255):
                if not((j>1 and image[j-1,i]==255) and (i>1 and image[j,i-1]==255) and (j<499 and image[j+1,i]==255) and (i<499 and image[j,i+1]==255)):
                    eroded[j,i]=0
                else:
                    eroded[j,i]=255
    return eroded

er=erosion(img)
cv2.namedWindow('main2')
cv2.imshow('main2', er)
cv2.waitKey(0)

print(np.array_equal(er,dil))

def closing(image):
    clf=dilation(image)
    cl=erosion(clf)
    return cl

cl=closing(img)
cv2.namedWindow('main4')
cv2.imshow('main4', cl)
cv2.waitKey(0)

print(np.array_equal(img,cl))
print(np.array_equal(cl,dil))
print(np.array_equal(cl,er))

def opening(image):
    opf=erosion(image)
    op=dilation(opf)
    return op

op=opening(img)
cv2.namedWindow('main5')
cv2.imshow('main5', cl)
cv2.waitKey(0)

print(np.array_equal(img,op))
print(np.array_equal(op,dil))
print(np.array_equal(op,er))

print(np.array_equal(op,cl))