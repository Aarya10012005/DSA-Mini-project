import csv

def reverse_transactions(input_file, output_file):
    # Read the input file
    with open(input_file, 'r', newline='', encoding='utf-8') as csvfile:
        reader = list(csv.reader(csvfile))
        
        # Extract the header and data
        header = reader[0]
        data = reader[1:]
        
        # Reverse the data rows and reassign serial numbers
        reversed_data = []
        for idx, row in enumerate(reversed(data), start=1):
            row[0] = str(idx)  # Update serial number
            reversed_data.append(row)
    
    # Write to the output file
    with open(output_file, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(header)  # Write header
        writer.writerows(reversed_data)  # Write reversed data with updated serial numbers

# Usage example
input_file = 'idbi.csv'  # Replace with your input file path
output_file = 'idbi_revised_date.csv'  # Replace with your desired output file path
reverse_transactions(input_file, output_file)

print("Transactions reversed and saved to", output_file)
