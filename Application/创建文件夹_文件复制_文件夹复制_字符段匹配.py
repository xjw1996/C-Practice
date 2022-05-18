from cgi import test
from itertools import count
import os
import shutil
import csv
from importlib.resources import path
from tokenize import Number
import openpyxl
from openpyxl.styles import Font
from openpyxl.styles import Alignment
from openpyxl.styles.borders import Border, Side

import pandas as pd
sql_dir_war="D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\报考策略数据\\2022年文科一本不同位次报考策略\\"
dbtype_list = os.listdir(sql_dir_war)
University_file_path="D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\2021和2020Excel合并版本\\成品\\文科一本"
University_list = os.listdir(University_file_path)
University_list_arr=[]

base_path="D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\报考策略数据\\成品\\文科一本\\"



def run():
    for Uni in University_list:
        University_list_arr.append(Uni)
    # print(len(University_list_arr))


    for dbtype in dbtype_list:

        str_arr = dbtype.split('.')
        name=str_arr[0]
        os.mkdir(base_path+name)
        
        os.mkdir(base_path+name+"\\"+"此次报考策略中所涉及到大学的具体数据")

        df = pd.read_excel('D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\报考策略数据\\2022年文科一本不同位次报考策略\\'+ dbtype)
        shutil.copytree('D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\专业\\2021年吉林文科本科一批院校专业分数线', base_path+name+"\\"+"2021年吉林文科本科一批院校专业分数线")
        os.mkdir(base_path+name+"\\"+"2021年吉林文科本科一批院校专业分数线\\中外合作专业与师范类专业")
        shutil.copy2('D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\报考策略数据\\2022年文科一本不同位次报考策略\\'+ dbtype, base_path+name)
        shutil.copy2('D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\专业\\师范类与中外合作文科一批\\师范类2021年在吉录取分数及位次.xlsx', base_path+name+"\\"+"2021年吉林文科本科一批院校专业分数线\\中外合作专业与师范类专业\\")
        shutil.copy2('D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\专业\\师范类与中外合作文科一批\\中外合作2021年在吉录取分数及位次.xlsx', base_path+name+"\\"+"2021年吉林文科本科一批院校专业分数线\\中外合作专业与师范类专业\\")
        
        arr=[]
        for row in df.values:
            # print(f'{row[2]}')
            # print(row[2])
            arr.append(str(row[2]))
            # print("count number is %d"% count)
        r=0
        for iterator in University_list_arr:
            for n in range(len(arr)):
                if(iterator.find(arr[n])!=-1):
                    print("关键词大学 %s"%arr[n])
                    print("大学excel为 %s"%iterator)
                    print("找到了")
                    shutil.copy2(University_file_path+ "\\" + iterator, base_path+name+"\\"+"此次报考策略中所涉及到大学的具体数据")

                # print(arr[n])
        print("======================================================================")
        arr=[]


        



if __name__ == "__main__":
    run()



