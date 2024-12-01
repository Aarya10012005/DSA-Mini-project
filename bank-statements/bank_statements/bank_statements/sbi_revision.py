import csv

def update_dates(input_file, output_file):
    # Full month mapping from abbreviations to numbers
    month_map = {
        "Jan": "01", "Feb": "02", "Mar": "03", "Apr": "04", "May": "05", "Jun": "06",
        "Jul": "07", "Aug": "08", "Sep": "09", "Oct": "10", "Nov": "11", "Dec": "12"
    }

    # Function to update the date format
    def format_date(date_str):
        day, month, year = date_str.split('-')
        # Replace month abbreviation with number
        month = month_map.get(month, month)
        # Ensure the year is in full (2023, 2024 format)
        year = '20' + year
        return f"{day}-{month}-{year}"

    # Read the input CSV file
    with open(input_file, 'r', newline='', encoding='utf-8') as csvfile:
        reader = csv.reader(csvfile)
        rows = list(reader)
        
        # Get the header and the data
        header = rows[0]
        data = rows[1:]
        
        # Update the dates in the relevant columns (Txn Date, Value Date)
        for row in data:
            row[1] = format_date(row[1])  # Update Txn Date
            row[2] = format_date(row[2])  # Update Value Date

    # Write the updated data to the output file
    with open(output_file, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(header)  # Write the header
        writer.writerows(data)   # Write the updated data

# Usage example
input_file = 'sbi.csv'  # Replace with your input file path
output_file = 'sbi_revised_format.csv'  # Replace with your desired output file path
update_dates(input_file, output_file)

print("Dates updated and saved to", output_file)
