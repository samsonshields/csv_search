import pandas as pd
import glob
import os

input_dir = "."
output_dir = "csv_out"
os.makedirs(output_dir, exist_ok=True)
xlsx_files = glob.glob(os.path.join(input_dir, "*.xlsx"))

for xlsx_file in xlsx_files:
    base_name = os.path.basename(xlsx_file)
    if base_name.startswith("~$"):
        continue
    csv_file = os.path.join(output_dir, base_name.replace(".xlsx", ".csv"))
    try:
        df = pd.read_excel(xlsx_file, engine="openpyxl")
        df.to_csv(csv_file, index=False)
        print(f"Converted: {base_name} -> {csv_file}")
    except Exception as e:
        print(f"Failed to convert {base_name}: {e}")
