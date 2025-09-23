import pandas as pd
import glob
import os

# Current directory
input_dir = "."

# Folder to store CSVs
output_dir = "csv_out"
os.makedirs(output_dir, exist_ok=True)

# Find all .xlsx files in the current folder
xlsx_files = glob.glob(os.path.join(input_dir, "*.xlsx"))

for xlsx_file in xlsx_files:
    base_name = os.path.basename(xlsx_file)

    # Skip Excel temporary files
    if base_name.startswith("~$"):
        continue

    # Output CSV path
    csv_file = os.path.join(output_dir, base_name.replace(".xlsx", ".csv"))

    try:
        # Read Excel file
        df = pd.read_excel(xlsx_file, engine="openpyxl")
        # Save as CSV
        df.to_csv(csv_file, index=False)
        print(f"Converted: {base_name} -> {csv_file}")
    except Exception as e:
        print(f"Failed to convert {base_name}: {e}")
