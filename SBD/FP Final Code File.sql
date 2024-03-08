CREATE TABLE customer (
    c_id CHAR(5) PRIMARY KEY NOT NULL,
    c_name VARCHAR(50) NOT NULL,
    c_phone VARCHAR(16) NULL,
    c_address VARCHAR(100) NULL,
    c_nik VARCHAR(16) NULL
);

CREATE TABLE employee (
    e_nik VARCHAR(16) PRIMARY KEY NOT NULL,
    e_name VARCHAR(50) NOT NULL,
    e_phone VARCHAR(16) NOT NULL,
    e_address VARCHAR(100) NOT NULL,
    e_position VARCHAR(30) NOT NULL,
	e_email VARCHAR(75) NOT NULL
);

CREATE TABLE computer (
    pc_id CHAR(6) PRIMARY KEY NOT NULL,
    pc_issue VARCHAR(200) NOT NULL,
    pc_serviceprice DECIMAL(15, 2) NOT NULL,
    customer_c_id CHAR(5) NOT NULL,
    FOREIGN KEY (customer_c_id) REFERENCES customer(c_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE supplier (
    s_id CHAR(5) PRIMARY KEY NOT NULL,
    s_name VARCHAR(20) NOT NULL
);

 CREATE TABLE product (
    p_id CHAR(5) PRIMARY KEY NOT NULL,
    p_type VARCHAR(20) NOT NULL,
    p_name VARCHAR(100) NOT NULL,
    p_price DECIMAL(15, 2) NOT NULL,
    p_connector VARCHAR(30) NOT NULL,
    supplier_s_id CHAR(5) NOT NULL,
    FOREIGN KEY (supplier_s_id) REFERENCES supplier(s_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE transactions (
    t_id CHAR(5) PRIMARY KEY NOT NULL,
    t_type VARCHAR(200) NOT NULL,
    t_method VARCHAR(20) NOT NULL,
    t_comment VARCHAR(200) NULL,
    t_date timestamp NOT NULL,
    t_finishdate timestamp NULL,
	t_totalprice decimal(15, 2) NULL,
    customer_c_id CHAR(5) NOT NULL,
    employee_e_nik VARCHAR(20) NOT NULL,
    computer_pc_id CHAR(6) NULL,
    FOREIGN KEY (customer_c_id) REFERENCES customer(c_id) ON UPDATE CASCADE ON DELETE CASCADE,
    FOREIGN KEY (employee_e_nik) REFERENCES employee(e_nik) ON UPDATE CASCADE ON DELETE CASCADE,
    FOREIGN KEY (computer_pc_id) REFERENCES computer(pc_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE transactions_product (
    transactions_t_id CHAR(5) NOT NULL,
    product_p_id CHAR(5) NOT NULL,
	FOREIGN KEY (transactions_t_id) REFERENCES transactions(t_id) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (product_p_id) REFERENCES product(p_id) ON UPDATE CASCADE ON DELETE CASCADE
);

insert into customer (c_id, c_name, c_phone, c_address, c_nik) values
('C0001', 'Alice Johnson', '555-1234', '123 Cherry Lane, Cityville, Stateburg, 56789', '98765432'),
('C0002', 'Bob Smith', '555-5678', '456 Pine Street, Townsville, Countyland, 67890', '87654321'),
('C0003', 'Chloe Davis', '555-9012', '789 Oak Avenue, Villagetown, Provinceland, 34567', '23456789'),
('C0004', 'David Brown', '555-3456', '101 Elm Road, Hamletville, Districtburg, 87654', '65432198'),
('C0005', 'Emily White', '555-7890', '202 Maple Lane, Suburbia, Regionville, 23456', '43219876'),
('C0006', 'Frank Miller', '555-2345', '303 Birch Street, Countryside, Territorytown, 76543', '78901234'),
('C0007', 'Grace Taylor', '555-6789', '404 Cedar Avenue, Hamletville, Stateburg, 12345', '87654321'),
('C0008', 'Henry Turner', '555-9012', '505 Pine Road, Townsville, Countyland, 65432', '34567890'),
('C0009', 'Isabella Moore', '555-3456', '606 Oak Lane, Villagetown, Provinceland, 98765', '65432198'),
('C0010', 'Jack Adams', '555-7890', '707 Elm Street, Cityville, Districtburg, 87654', '23456789'),
('C0011', 'Olivia Turner', '555-1234', '808 Birch Avenue, Suburbia, Regionville, 34567', '78901234'),
('C0012', 'Liam Harris', '555-5678', '909 Cedar Road, Countryside, Territorytown, 87654', '12345678'),
('C0013', 'Ava Martinez', '555-9012', '1010 Pine Lane, Villagetown, Provinceland, 23456', '56789012'),
('C0014', 'Noah Evans', '555-3456', '1111 Oak Street, Cityville, Stateburg, 76543', '89012345'),
('C0015', 'Sophia Clark', '555-6789', '1212 Elm Avenue, Hamletville, Districtburg, 43210', '21098765'),
('C0016', 'Jackson Allen', '555-2345', '1313 Birch Road, Townsville, Countyland, 87654', '54321098'),
('C0017', 'Emma Rodriguez', '555-7890', '1414 Cedar Lane, Suburbia, Regionville, 98765', '10987654'),
('C0018', 'Aiden Murphy', '555-0123', '1515 Pine Street, Countryside, Territorytown, 65432', '87654321'),
('C0019', 'Harper Wilson', '555-4567', '1616 Oak Road, Villagetown, Provinceland, 32109', '98765432'),
('C0020', 'Ethan Baker', '555-8901', '1717 Elm Lane, Cityville, Stateburg, 54321', '23456789'),
('C0021', 'Zoey Garcia', '555-1234', '1818 Birch Street, Hamletville, Districtburg, 21098', '87654321'),
('C0022', 'Mason Wright', '555-5678', '1919 Cedar Avenue, Townsville, Countyland, 89012', '12345678'),
('C0023', 'Addison Hall', '555-9012', '2020 Pine Road, Suburbia, Regionville, 65432', '56789012'),
('C0024', 'Elijah Foster', '555-3456', '2121 Oak Lane, Countryside, Territorytown, 12345', '89012345'),
('C0025', 'Scarlett Simmons', '555-6789', '2222 Elm Street, Villagetown, Provinceland, 67890', '21098765'),
('C0026', 'Oliver Powell', '555-2345', '2323 Birch Road, Cityville, Stateburg, 98765', '54321098'),
('C0027', 'Mia Martinez', '555-7890', '2424 Cedar Lane, Hamletville, Districtburg, 21098', '87654321'),
('C0028', 'Carter Bailey', '555-0123', '2525 Pine Street, Townsville, Countyland, 89012', '12345678'),
('C0029', 'Lily Davis', '555-4567', '2626 Oak Road, Suburbia, Regionville, 54321', '56789012'),
('C0030', 'Lucas Taylor', '555-8901', '2727 Elm Avenue, Countryside, Territorytown, 32109', '23456789'),
('C0031', 'Amelia Foster', '555-1234', '2828 Birch Street, Villagetown, Provinceland, 87654', '98765432'),
('C0032', 'Benjamin Wright', '555-5678', '2929 Cedar Avenue, Cityville, Stateburg, 56789', '12345678'),
('C0033', 'Stella Baker', '555-9012', '3030 Pine Road, Hamletville, Districtburg, 23456', '67890123'),
('C0034', 'Leo Hall', '555-3456', '3131 Oak Lane, Townsville, Countyland, 87654', '34567890'),
('C0035', 'Evelyn Allen', '555-6789', '3232 Elm Street, Suburbia, Regionville, 10987', '89012345'),
('C0036', 'Caleb Powell', '555-2345', '3333 Birch Road, Countryside, Territorytown, 54321', '21098765'),
('C0037', 'Sofia Simmons', '555-7890', '3434 Cedar Lane, Villagetown, Provinceland, 87654', '98765432'),
('C0038', 'Daniel Murphy', '555-0123', '3535 Pine Street, Cityville, Stateburg, 32109', '12345678'),
('C0039', 'Aurora Davis', '555-4567', '3636 Oak Road, Hamletville, Districtburg, 65432', '56789012'),
('C0040', 'Jackson Baker', '555-8901', '3737 Elm Avenue, Townsville, Countyland, 21098', '23456789');

insert into supplier (s_id, s_name) values
('S0001', 'ASUS'),
('S0002', 'Intel'),
('S0003', 'Corsair'),
('S0004', 'Samsung'),
('S0005', 'MSI'),
('S0006', 'NVIDIA'),
('S0007', 'AMD'),
('S0008', 'G.Skill'),
('S0009', 'WD (Western Digital)'),
('S0010', 'ASRock'),
('S0011', 'EVGA'),
('S0012', 'HyperX'),
('S0013', 'Crucial'),
('S0014', 'Gigabyte'),
('S0015', 'Team'),
('S0016', 'Kingston'),
('S0017', 'Logitech'),
('S0018', 'Razer'),
('S0019', 'SteelSeries'),
('S0020', 'LG'),
('S0021', 'Dell'),
('S0022', 'Acer'),
('S0023', 'ViewSonic'),
('S0024', 'BenQ'),
('S0025', 'Ducky'),
('S0026', 'Anne'),
('S0027', 'Finalmouse'),
('S0028', 'Glorious'),
('S0029', 'NZXT'),
('S0030', 'Seagate'),
('S0031', 'Zotac'),
('S0032', 'Cooler Master'),
('S0033', 'Fractal Design'),
('S0034', 'PowerColor'),
('S0035', 'Sapphire'),
('S0036', 'Adata'),
('S0037', 'Thermaltake'),
('S0038', 'Noctua');

insert into product (p_id, p_type, p_name, p_price, p_connector, supplier_s_id) values
('P0001', 'GPU', 'ASUS RTX 2080', 5000000.00, 'PCIe x16', 'S0001'),
('P0002', 'CPU', 'Intel Core i7-9700K', 3000000.00, 'LGA 1151', 'S0002'),
('P0003', 'RAM', 'Corsair Vengeance LPX 16GB', 1500000.00, 'DDR4', 'S0003'),
('P0004', 'Storage', 'Samsung 970 EVO 1TB SSD', 2000000.00, 'M.2', 'S0004'),
('P0005', 'Motherboard', 'MSI MPG Z390 GAMING PRO CARBON AC', 2500000.00, 'ATX', 'S0005'),
('P0006', 'GPU', 'NVIDIA GTX 1660 Ti', 1200000.00, 'PCIe x16', 'S0006'),
('P0007', 'CPU', 'AMD Ryzen 5 3600X', 2500000.00, 'AM4', 'S0007'),
('P0008', 'RAM', 'G.Skill Ripjaws V 32GB', 1800000.00, 'DDR4', 'S0008'),
('P0009', 'Storage', 'WD Blue 2TB HDD', 1000000.00, 'SATA', 'S0009'),
('P0010', 'Motherboard', 'ASRock B450M PRO4', 1500000.00, 'Micro-ATX', 'S0010'),
('P0011', 'GPU', 'EVGA GeForce RTX 3060', 2200000.00, 'PCIe x16', 'S0011'),
('P0012', 'CPU', 'Intel Core i9-9900K', 4000000.00, 'LGA 1151', 'S0002'),
('P0013', 'RAM', 'HyperX Fury 8GB', 800000.00, 'DDR4', 'S0012'),
('P0014', 'Storage', 'Crucial MX500 500GB SSD', 1200000.00, '2.5" SATA', 'S0013'),
('P0015', 'Motherboard', 'Gigabyte B550 AORUS ELITE', 1800000.00, 'ATX', 'S0014'),
('P0016', 'GPU', 'AMD Radeon RX 5700 XT', 1700000.00, 'PCIe x16', 'S0007'),
('P0017', 'CPU', 'AMD Ryzen 7 5800X', 3500000.00, 'AM4', 'S0007'),
('P0018', 'RAM', 'Corsair Dominator Platinum 64GB', 3000000.00, 'DDR4', 'S0003'),
('P0019', 'Storage', 'Seagate Barracuda 4TB HDD', 1600000.00, 'SATA', 'S0030'),
('P0020', 'Motherboard', 'ASUS ROG Strix X570-E Gaming', 2800000.00, 'ATX', 'S0001'),
('P0021', 'GPU', 'NVIDIA RTX 3070', 2800000.00, 'PCIe x16', 'S0006'),
('P0022', 'CPU', 'Intel Core i5-11600K', 2200000.00, 'LGA 1200', 'S0002'),
('P0023', 'RAM', 'Team T-FORCE VULCAN Z 32GB', 1700000.00, 'DDR4', 'S0015'),
('P0024', 'Storage', 'Kingston A2000 1TB NVMe SSD', 1800000.00, 'M.2', 'S0016'),
('P0025', 'Motherboard', 'MSI B450 TOMAHAWK MAX', 1400000.00, 'ATX', 'S0005'),
('P0026', 'GPU', 'AMD Radeon RX 6800', 3500000.00, 'PCIe x16', 'S0007'),
('P0027', 'CPU', 'AMD Ryzen 9 5900X', 5000000.00, 'AM4', 'S0007'),
('P0028', 'RAM', 'Crucial Ballistix 16GB', 1300000.00, 'DDR4', 'S0013'),
('P0029', 'Storage', 'Western Digital Black 6TB HDD', 2400000.00, 'SATA', 'S0009'),
('P0030', 'Motherboard', 'ASRock X570 Phantom Gaming-ITX/TB3', 2000000.00, 'Mini-ITX', 'S0010'),
('P0031', 'Monitor', 'Dell 27-inch 4K UHD Monitor', 1500000.00, 'DisplayPort, HDMI, USB-A', 'S0021'),
('P0032', 'Mouse', 'Logitech G Pro Wireless Gaming Mouse', 1000000.00, 'USB-A, Wireless', 'S0017'),
('P0033', 'Keyboard', 'Corsair K95 RGB Platinum XT Mechanical Keyboard', 2000000.00, 'USB-A', 'S0003'),
('P0034', 'Monitor', 'LG 34-inch Ultrawide QHD Curved Monitor', 1800000.00, 'HDMI, DisplayPort, USB-C', 'S0020'),
('P0035', 'Mouse', 'Razer DeathAdder Elite Gaming Mouse', 800000.00, 'USB-A', 'S0018'),
('P0036', 'Keyboard', 'SteelSeries Apex Pro Mechanical Gaming Keyboard', 2500000.00, 'USB-A', 'S0019'),
('P0037', 'Monitor', 'ASUS ROG Swift PG279Q 27-inch Gaming Monitor', 1600000.00, 'DisplayPort, HDMI, USB-A', 'S0001'),
('P0038', 'Mouse', 'Corsair Dark Core RGB/SE Wired/Wireless Gaming Mouse', 1200000.00, 'USB-A, Wireless', 'S0003'),
('P0039', 'Keyboard', 'Ducky One 2 Mini Mechanical Keyboard', 1800000.00, 'USB-C', 'S0025'),
('P0040', 'Monitor', 'Samsung Odyssey G7 32-inch Curved Gaming Monitor', 2000000.00, 'HDMI, DisplayPort, USB-C', 'S0004'),
('P0041', 'Mouse', 'Logitech MX Master 3 Wireless Mouse', 1500000.00, 'USB-C, Bluetooth', 'S0017'),
('P0042', 'Keyboard', 'Anne Pro 2 Mechanical Gaming Keyboard', 1300000.00, 'USB-C, Bluetooth', 'S0026'),
('P0043', 'Monitor', 'Acer Predator X34P 34-inch QHD Curved Gaming Monitor', 1900000.00, 'HDMI, DisplayPort, USB-A', 'S0022'),
('P0044', 'Mouse', 'SteelSeries Rival 600 Gaming Mouse', 1100000.00, 'USB-A', 'S0019'),
('P0045', 'Keyboard', 'Logitech G Pro X Mechanical Gaming Keyboard', 2200000.00, 'USB-A', 'S0017'),
('P0046', 'Monitor', 'ViewSonic XG2402 24-inch 1080p Gaming Monitor', 1200000.00, 'HDMI, DisplayPort, USB-A', 'S0023'),
('P0047', 'Mouse', 'Finalmouse Ultralight 2 Cape Town', 900000.00, 'USB-A', 'S0027'),
('P0048', 'Keyboard', 'Razer BlackWidow Elite Mechanical Gaming Keyboard', 1600000.00, 'USB-A', 'S0018'),
('P0049', 'Monitor', 'BenQ EX2780Q 27-inch 1440p Gaming Monitor', 1700000.00, 'HDMI, DisplayPort, USB-C', 'S0024'),
('P0050', 'Mouse', 'Glorious Model O Gaming Mouse', 700000.00, 'USB-A', 'S0028'),
('P0051', 'CPU', 'AMD Ryzen 5 5600X', 2800000.00, 'AM4', 'S0007'),
('P0052', 'Motherboard', 'ASUS ROG Strix B550-F Gaming', 2300000.00, 'ATX', 'S0001'),
('P0053', 'RAM', 'Crucial Ballistix RGB 32GB', 2000000.00, 'DDR4', 'S0013'),
('P0054', 'GPU', 'MSI GeForce GTX 1660 SUPER', 1500000.00, 'PCIe x16', 'S0005'),
('P0055', 'Storage', 'Samsung 970 EVO Plus 500GB NVMe SSD', 1600000.00, 'M.2', 'S0004'),
('P0056', 'Power Supply', 'EVGA SuperNOVA 650 G5', 1000000.00, 'ATX', 'S0011'),
('P0057', 'CPU Cooler', 'NZXT Kraken X53 240mm AIO Liquid Cooler', 1800000.00, 'USB, PWM', 'S0029'),
('P0058', 'Case', 'NZXT H510i Compact ATX Mid-Tower', 1200000.00, 'USB, Audio, HDMI', 'S0029'),
('P0059', 'Storage', 'Seagate Barracuda 2TB HDD', 800000.00, 'SATA', 'S0030'),
('P0060', 'GPU', 'ASRock Radeon RX 6700 XT', 2500000.00, 'PCIe x16', 'S0010'),
('P0061', 'Motherboard', 'Gigabyte B450M DS3H', 900000.00, 'Micro-ATX', 'S0014'),
('P0062', 'RAM', 'Team T-FORCE DARK Z 16GB', 800000.00, 'DDR4', 'S0015'),
('P0063', 'GPU', 'ZOTAC Gaming GeForce GTX 1660', 1200000.00, 'PCIe x16', 'S0031'),
('P0064', 'Storage', 'Crucial P1 1TB NVMe SSD', 1400000.00, 'M.2', 'S0013'),
('P0065', 'Power Supply', 'Corsair CV550, CV Series, CV550, 80 PLUS Bronze', 700000.00, 'ATX', 'S0003'),
('P0066', 'CPU Cooler', 'Cooler Master Hyper 212 RGB', 1000000.00, 'PWM', 'S0032'),
('P0067', 'Case', 'Fractal Design Meshify C ATX Mid Tower', 1500000.00, 'USB, Audio', 'S0033'),
('P0068', 'Storage', 'Western Digital Blue 500GB SSD', 1100000.00, '2.5" SATA', 'S0009'),
('P0069', 'GPU', 'PowerColor Red Dragon Radeon RX 580', 800000.00, 'PCIe x16', 'S0034'),
('P0070', 'CPU', 'Intel Core i5-10400F', 1700000.00, 'LGA 1200', 'S0002'),
('P0071', 'Motherboard', 'ASRock H470M-ITX/ac Mini ITX', 1200000.00, 'Mini-ITX', 'S0010'),
('P0072', 'RAM', 'Kingston HyperX Fury 8GB DDR4', 600000.00, 'DDR4', 'S0016'),
('P0073', 'GPU', 'Sapphire Pulse Radeon RX 5500 XT', 1100000.00, 'PCIe x16', 'S0035'),
('P0074', 'Storage', 'ADATA SU635 240GB SATA SSD', 400000.00, '2.5" SATA', 'S0036'),
('P0075', 'Power Supply', 'Thermaltake Smart 500W 80+ White', 500000.00, 'ATX', 'S0037'),
('P0076', 'CPU Cooler', 'Noctua NH-L9a-AM4 Low-Profile Cooler', 900000.00, 'PWM', 'S0038'),
('P0077', 'Case', 'NZXT H200i Mini-ITX Tower', 1300000.00, 'USB, Audio', 'S0029'),
('P0078', 'Storage', 'Crucial MX500 1TB SATA SSD', 1500000.00, '2.5" SATA', 'S0013'),
('P0079', 'GPU', 'EVGA GeForce GT 1030 SC', 700000.00, 'PCIe x16', 'S0011'),
('P0080', 'CPU', 'AMD Ryzen 3 3200G', 800000.00, 'AM4', 'S0007');

INSERT INTO employee (e_nik, e_name, e_phone, e_address, e_position, e_email) VALUES
('98765432', 'Alex Johnson', '555-1111', '456 Oak Street, Citytown, Districtburg, 56789', 'PC Mechanic', 'alex.johnson@example.com'),
('82321321', 'Beth Davis', '555-2222', '789 Pine Road, Townsville, Stateburg, 67890', 'Cashier', 'beth.davis@example.com'),
('23456789', 'Chris Smith', '555-3333', '101 Elm Lane, Villagetown, Countyland, 34567', 'PC Mechanic', 'chris.smith@example.com'),
('65432198', 'Diana Miller', '555-4444', '202 Maple Road, Suburbia, Provinceland, 45678', 'PC Mechanic', 'diana.miller@example.com'),
('43219876', 'Ethan Turner', '555-5555', '303 Cedar Street, Countryside, Territorytown, 98765', 'Cashier', 'ethan.turner@example.com'),
('78901234', 'Fiona White', '555-6666', '404 Birch Avenue, Hamletville, Regionville, 87654', 'PC Mechanic', 'fiona.white@example.com'),
('87654321', 'George Baker', '555-7777', '505 Oak Lane, Cityville, Districtburg, 76543', 'Manager', 'george.baker@example.com'),
('34567890', 'Hannah Taylor', '555-8888', '606 Pine Road, Townsville, Stateburg, 65432', 'Cashier', 'hannah.taylor@example.com'),
('62322198', 'Ian Brown', '555-9999', '707 Elm Street, Villagetown, Countyland, 54321', 'PC Mechanic', 'ian.brown@example.com'),
('23423389', 'Julia Clark', '555-0000', '808 Maple Avenue, Suburbia, Provinceland, 43210', 'Manager', 'julia.clark@example.com'),
('98765435', 'Lily Martinez', '555-1112', '124 Pine Lane, Citytown, Districtburg, 56789', 'PC Mechanic', 'lily.martinez@example.com'),
('82321111', 'Michael Adams', '555-2223', '457 Oak Street, Townsville, Stateburg, 67890', 'Cashier', 'michael.adams@example.com'),
('23456787', 'Olivia Wilson', '555-3334', '790 Maple Road, Villagetown, Countyland, 34567', 'PC Mechanic', 'olivia.wilson@example.com'),
('65432199', 'Peter Garcia', '555-4445', '102 Cedar Street, Suburbia, Provinceland, 45678', 'PC Mechanic', 'peter.garcia@example.com'),
('43219877', 'Samantha Turner', '555-5556', '203 Birch Avenue, Countryside, Territorytown, 98765', 'Cashier', 'samantha.turner@example.com'),
('78901236', 'Tom Wright', '555-6667', '304 Elm Lane, Hamletville, Regionville, 87654', 'PC Mechanic', 'tom.wright@example.com'),
('87654323', 'Violet Davis', '555-7778', '405 Pine Road, Cityville, Districtburg, 76543', 'Cashier', 'violet.davis@example.com'),
('34567892', 'William Baker', '555-8889', '506 Maple Road, Townsville, Stateburg, 65432', 'PC Mechanic', 'william.baker@example.com'),
('62322332', 'Sophie Taylor', '555-9990', '607 Cedar Street, Villagetown, Countyland, 54321', 'PC Mechanic', 'sophie.taylor@example.com'),
('23423567', 'Eli Clark', '555-0001', '808 Maple Avenue, Suburbia, Provinceland, 43210', 'Cashier', 'eli.clark@example.com'),
('86543210', 'Aria Turner', '555-1113', '125 Pine Lane, Citytown, Districtburg, 56789', 'PC Mechanic', 'aria.turner@example.com'),
('87651235', 'Nathan Harris', '555-2224', '458 Oak Street, Townsville, Stateburg, 67890', 'Cashier', 'nathan.harris@example.com'),
('43210988', 'Mila Evans', '555-3335', '791 Maple Road, Villagetown, Countyland, 34567', 'PC Mechanic', 'mila.evans@example.com'),
('98762346', 'Owen Baker', '555-4446', '103 Cedar Street, Suburbia, Provinceland, 45678', 'PC Mechanic', 'owen.baker@example.com'),
('78903457', 'Penelope White', '555-5557', '204 Birch Avenue, Countryside, Territorytown, 98765', 'Cashier', 'penelope.white@example.com'),
('56789023', 'Quincy Johnson', '555-6668', '305 Elm Lane, Hamletville, Regionville, 87654', 'PC Mechanic', 'quincy.johnson@example.com'),
('43216544', 'Ruby Turner', '555-7779', '406 Pine Road, Cityville, Districtburg, 76543', 'Cashier', 'ruby.turner@example.com'),
('98760124', 'Simon Clark', '555-8890', '507 Maple Road, Townsville, Stateburg, 65432', 'PC Mechanic', 'simon.clark@example.com'),
('87651236', 'Tara Davis', '555-9991', '608 Cedar Street, Villagetown, Countyland, 54321', 'PC Mechanic', 'tara.davis@example.com'),
('12349088', 'Upton Smith', '555-0002', '808 Birch Avenue, Suburbia, Provinceland, 43210', 'Cashier', 'upton.smith@example.com'),
('23456790', 'Valerie Harris', '555-1114', '126 Pine Lane, Citytown, Districtburg, 56789', 'PC Mechanic', 'valerie.harris@example.com'),
('34567891', 'Winston Baker', '555-2225', '459 Oak Street, Townsville, Stateburg, 67890', 'Cashier', 'winston.baker@example.com'),
('45678902', 'Xander Evans', '555-3336', '792 Maple Road, Villagetown, Countyland, 34567', 'PC Mechanic', 'xander.evans@example.com'),
('56789013', 'Yara Baker', '555-4447', '104 Cedar Street, Suburbia, Provinceland, 45678', 'PC Mechanic', 'yara.baker@example.com'),
('67890124', 'Zane Turner', '555-5558', '205 Birch Avenue, Countryside, Territorytown, 98765', 'Cashier', 'zane.turner@example.com'),
('78901235', 'Amelia Turner', '555-6669', '306 Elm Lane, Hamletville, Regionville, 87654', 'PC Mechanic', 'amelia.turner@example.com'),
('89012346', 'Benjamin Clark', '555-7780', '407 Pine Road, Cityville, Districtburg, 76543', 'Cashier', 'benjamin.clark@example.com'),
('90123457', 'Cassandra Harris', '555-8891', '508 Maple Road, Townsville, Stateburg, 65432', 'PC Mechanic', 'cassandra.harris@example.com'),
('12345679', 'Dylan Baker', '555-9992', '609 Cedar Street, Villagetown, Countyland, 54321', 'PC Mechanic', 'dylan.baker@example.com'),
('11111111', 'Zara Turner', '555-1234', '123 Oak Street, Citytown, Districtburg, 56789', 'Cashier', 'zara.turner@example.com'),
('22222222', 'Xavier Smith', '555-5678', '456 Pine Road, Townsville, Stateburg, 67890', 'PC Mechanic', 'xavier.smith@example.com');



insert into computer (pc_id, pc_issue, pc_serviceprice, customer_c_id) values
('PC0001', 'It keeps going into bluescreen frequently', 50000.00, 'C0002'),
('PC0002', 'Slow performance and overheating', 75000.00, 'C0005'),
('PC0003', 'Cannot boot up, showing error message', 50000.00, 'C0014'),
('PC0004', 'Random shutdowns without warning', 50000.00, 'C0015'),
('PC0005', 'Fans dont speed up when gaming', 50000.00, 'C0034'),
('PC0006', 'PC got slower', 75000.00, 'C0035');

insert into transactions (t_id, t_type, t_method, t_comment, t_date, t_finishdate, customer_c_id, employee_e_nik, computer_pc_id) values
('T0001', 'Purchase', 'Card', NULL, '2023-01-16 09:45:00', NULL, 'C0001', '82321321', NULL),
('T0002', 'Service', 'Cash', NULL, '2023-01-19 09:35:00', '2023-01-21 10:45:00', 'C0002', '98765432', 'PC0001'),
('T0003', 'Build', 'Card', 'Build me a pc that is not too expensive but is okay for work', '2023-01-20 13:35:00', '2023-01-25 15:36:00', 'C0003', '23456789', NULL),
('T0004', 'Purchase', 'Cash', NULL, '2023-01-20 15:23:00', NULL, 'C0004', '43219876', NULL),
('T0005', 'Service', 'Cash', NULL, '2023-01-21 12:15:00', '2023-01-22 10:10:00', 'C0005', '65432198', 'PC0002'),
('T0006', 'Purchase', 'Card', NULL, '2023-01-21 13:54:00', NULL, 'C0006', '43219876', NULL),
('T0007', 'Purchase', 'Cash', NULL, '2023-01-22 09:24:00', NULL, 'C0007', '82321321', NULL),
('T0008', 'Purchase', 'Cash', NULL, '2023-01-24 13:35:00', NULL, 'C0008', '34567890', NULL),
('T0009', 'Purchase', 'Card', NULL, '2023-01-24 14:15:00', NULL, 'C0009', '82321321', NULL),
('T0010', 'Purchase', 'Card', NULL, '2023-01-27 12:45:00', NULL, 'C0010', '43219876', NULL),
('T0011', 'Purchase', 'Cash', NULL, '2023-01-28 09:12:00', NULL, 'C0011', '34567890', NULL),
('T0012', 'Purchase', 'Card', NULL, '2023-01-28 16:15:00', NULL, 'C0012', '43219876', NULL),
('T0013', 'Purchase', 'Card', NULL, '2023-01-29 11:21:00', NULL, 'C0013', '34567890', NULL),
('T0014', 'Service', 'Cash', NULL, '2023-01-29 09:35:00', '2023-01-30 14:13:00', 'C0014', '78901234', 'PC0003'),
('T0015', 'Service', 'Cash', NULL, '2023-01-30 13:56:00', '2023-01-31 10:15:00', 'C0015', '98765432', 'PC0004'),
('T0016', 'Purchase', 'Cash', NULL, '2023-02-01 09:35:00', NULL, 'C0016', '34567890', NULL),
('T0017', 'Purchase', 'Card', NULL, '2023-02-03 10:15:00', NULL, 'C0017', '82321321', NULL),
('T0018', 'Purchase', 'Card', NULL, '2023-02-03 11:25:00', NULL, 'C0018', '43219876', NULL),
('T0019', 'Purchase', 'Cash', NULL, '2023-02-03 15:12:00', NULL, 'C0019', '34567890', NULL),
('T0020', 'Purchase', 'Card', NULL, '2023-02-04 09:35:00', NULL, 'C0020', '43219876', NULL),
('T0021', 'Purchase', 'Card', NULL, '2023-02-06 11:25:00', NULL, 'C0021', '34567890', NULL),
('T0022', 'Build', 'Card', 'Build me an awesome gaming pc', '2023-02-06 15:32:00', '2023-02-13 16:00:00', 'C0022', '78901234', NULL),
('T0023', 'Purchase', 'Cash', NULL, '2023-02-07 09:25:00', NULL, 'C0023', '34567890', NULL),
('T0024', 'Purchase', 'Card', NULL, '2023-02-07 11:35:00', NULL, 'C0024', '82321321', NULL),
('T0025', 'Purchase', 'Card', NULL, '2023-02-08 10:43:00', NULL, 'C0025', '43219876', NULL),
('T0026', 'Purchase', 'Cash', NULL, '2023-02-10 09:15:00', NULL, 'C0026', '34567890', NULL),
('T0027', 'Purchase', 'Card', NULL, '2023-02-11 12:15:00', NULL, 'C0027', '43219876', NULL),
('T0028', 'Purchase', 'Card', NULL, '2023-02-11 13:25:00', NULL, 'C0028', '82321321', NULL),
('T0029', 'Purchase', 'Card', NULL, '2023-02-13 09:55:00', NULL, 'C0029', '43219876', NULL),
('T0030', 'Purchase', 'Cash', NULL, '2023-02-16 09:30:00', NULL, 'C0030', '34567890', NULL),
('T0031', 'Purchase', 'Card', NULL, '2023-02-16 15:45:00', NULL, 'C0031', '82321321', NULL),
('T0032', 'Purchase', 'Card', NULL, '2023-02-17 09:15:00', NULL, 'C0032', '34567890', NULL),
('T0033', 'Service', 'Cash', NULL, '2023-02-19 10:45:00', '2023-02-20 14:00:00', 'C0034', '78901234', 'PC0005'),
('T0034', 'Build', 'Card', 'Build me a cheap office pc', '2023-02-20 09:35:00', '2023-02-27 11:15:00', 'C0034', '62322198', NULL),
('T0035', 'Service', 'Cash', NULL, '2023-02-20 13:25:00', '2023-02-21 11:32:00', 'C0035', '23456789', 'PC0006'),
('T0036', 'Purchase', 'Card', NULL, '2023-02-21 11:35:00', NULL, 'C0036', '43219876', NULL),
('T0037', 'Purchase', 'Cash', NULL, '2023-02-22 12:55:00', NULL, 'C0037', '82321321', NULL),
('T0038', 'Purchase', 'Cash', NULL, '2023-02-24 15:45:00', NULL, 'C0038', '82321321', NULL),
('T0039', 'Purchase', 'Card', NULL, '2023-02-24 16:55:00', NULL, 'C0039', '34567890', NULL),
('T0040', 'Purchase', 'Card', NULL, '2023-02-27 14:25:51', NULL, 'C0040', '43219876', NULL),
('T0041', 'Purchase', 'Card', NULL, '2023-02-28 16:11:37', NULL, 'C0001', '43219876', NULL),
('T0042', 'Purchase', 'Cash', NULL, '2023-03-01 12:22:25', NULL, 'C0002', '89012346', NULL),
('T0043', 'Purchase', 'Card', NULL, '2023-03-02 13:02:50', NULL, 'C0003', '23456789', NULL),
('T0044', 'Purchase', 'Card', NULL, '2023-03-03 11:39:20', NULL, 'C0004', '82321111', NULL),
('T0045', 'Purchase', 'Cash', NULL, '2023-03-03 13:18:39', NULL, 'C0005', '65432198', NULL),
('T0046', 'Purchase', 'Card', NULL, '2023-03-04 11:17:17', NULL, 'C0006', '82321111', NULL),
('T0047', 'Purchase', 'Cash', NULL, '2023-03-06 14:12:58', NULL, 'C0007', '12349088', NULL),
('T0048', 'Purchase', 'Card', NULL, '2023-03-07 14:43:03', NULL, 'C0008', '34567890', NULL),
('T0049', 'Purchase', 'Card', NULL, '2023-03-07 15:41:33', NULL, 'C0009', '12349088', NULL),
('T0050', 'Purchase', 'Cash', NULL, '2023-03-09 11:22:48', NULL, 'C0010', '43219876', NULL),
('T0051', 'Purchase', 'Card', NULL, '2023-03-10 14:58:34', NULL, 'C0011', '34567890', NULL),
('T0052', 'Purchase', 'Card', NULL, '2023-03-10 14:35:12', NULL, 'C0012', '43219876', NULL),
('T0053', 'Purchase', 'Cash', NULL, '2023-03-11 12:57:13', NULL, 'C0013', '87651235', NULL),
('T0054', 'Purchase', 'Card', NULL, '2023-03-13 13:09:31', NULL, 'C0014', '89012346', NULL),
('T0055', 'Purchase', 'Cash', NULL, '2023-03-13 16:39:25', NULL, 'C0015', '12349088', NULL),
('T0056', 'Purchase', 'Card', NULL, '2023-03-14 09:14:43', NULL, 'C0016', '87651235', NULL),
('T0057', 'Purchase', 'Card', NULL, '2023-03-16 14:55:34', NULL, 'C0017', '82321321', NULL),
('T0058', 'Purchase', 'Cash', NULL, '2023-03-17 14:12:54', NULL, 'C0018', '89012346', NULL),
('T0059', 'Purchase', 'Card', NULL, '2023-03-17 11:29:01', NULL, 'C0019', '34567890', NULL),
('T0060', 'Purchase', 'Card', NULL, '2023-03-18 16:01:25', NULL, 'C0020', '43219876', NULL),
('T0061', 'Purchase', 'Cash', NULL, '2023-03-20 16:42:08', NULL, 'C0021', '34567890', NULL),
('T0062', 'Purchase', 'Card', NULL, '2023-03-20 15:23:24', NULL, 'C0022', '78901234', NULL),
('T0063', 'Purchase', 'Card', NULL, '2023-03-21 14:21:16', NULL, 'C0023', '34567890', NULL),
('T0064', 'Purchase', 'Cash', NULL, '2023-03-22 14:25:20', NULL, 'C0024', '82321321', NULL),
('T0065', 'Purchase', 'Card', NULL, '2023-03-24 13:21:19', NULL, 'C0025', '82321111', NULL),
('T0066', 'Purchase', 'Card', NULL, '2023-03-25 15:07:58', NULL, 'C0026', '87651235', NULL),
('T0067', 'Purchase', 'Cash', NULL, '2023-03-27 16:23:37', NULL, 'C0027', '12349088', NULL),
('T0068', 'Purchase', 'Card', NULL, '2023-03-28 10:44:28', NULL, 'C0028', '82321321', NULL),
('T0069', 'Purchase', 'Card', NULL, '2023-03-29 11:24:22', NULL, 'C0029', '89012346', NULL),
('T0070', 'Purchase', 'Cash', NULL, '2023-03-31 14:38:02', NULL, 'C0030', '87651235', NULL),
('T0071', 'Purchase', 'Card', NULL, '2023-03-31 13:54:17', NULL, 'C0031', '82321321', NULL),
('T0072', 'Purchase', 'Card', NULL, '2023-04-01 14:55:23', NULL, 'C0032', '34567890', NULL),
('T0073', 'Purchase', 'Cash', NULL, '2023-04-03 13:28:53', NULL, 'C0033', '82321321', NULL),
('T0074', 'Purchase', 'Card', NULL, '2023-04-03 11:27:37', NULL, 'C0034', '98765432', NULL),
('T0075', 'Purchase', 'Card', NULL, '2023-04-04 16:48:49', NULL, 'C0035', '87651235', NULL),
('T0076', 'Purchase', 'Cash', NULL, '2023-04-05 13:01:50', NULL, 'C0036', '43219876', NULL),
('T0077', 'Purchase', 'Card', NULL, '2023-04-05 09:37:50', NULL, 'C0037', '82321321', NULL),
('T0078', 'Purchase', 'Card', NULL, '2023-04-06 15:48:33', NULL, 'C0038', '34567890', NULL),
('T0079', 'Purchase', 'Cash', NULL, '2023-04-07 16:10:46', NULL, 'C0039', '82321321', NULL),
('T0080', 'Purchase', 'Card', NULL, '2023-04-07 15:50:20', NULL, 'C0040', '12349088', NULL);

insert into transactions_product (transactions_t_id, product_p_id) values
('T0001', 'P0001'),
('T0001', 'P0002'),
('T0003', 'P0071'),
('T0003', 'P0072'),
('T0003', 'P0073'),
('T0003', 'P0078'),
('T0003', 'P0075'),
('T0003', 'P0077'),
('T0003', 'P0080'),
('T0004', 'P0002'),
('T0004', 'P0004'),
('T0004', 'P0057'),
('T0004', 'P0005'),
('T0005', 'P0066'),
('T0006', 'P0026'),
('T0006', 'P0027'),
('T0006', 'P0018'),
('T0006', 'P0015'),
('T0006', 'P0019'),
('T0006', 'P0004'),
('T0006', 'P0056'),
('T0006', 'P0058'),
('T0006', 'P0057'),
('T0007', 'P0066'),
('T0007', 'P0064'),
('T0008', 'P0031'),
('T0009', 'P0034'),
('T0010', 'P0037'),
('T0011', 'P0040'),
('T0012', 'P0043'),
('T0013', 'P0032'),
('T0013', 'P0033'),
('T0016', 'P0034'),
('T0017', 'P0037'),
('T0018', 'P0040'),
('T0019', 'P0043'),
('T0020', 'P0032'),
('T0021', 'P0033'),
('T0022', 'P0060'),
('T0022', 'P0017'),
('T0022', 'P0033'),
('T0022', 'P0020'),
('T0022', 'P0023'),
('T0022', 'P0024'),
('T0022', 'P0056'),
('T0022', 'P0057'),
('T0022', 'P0058'),
('T0023', 'P0039'),
('T0024', 'P0029'),
('T0024', 'P0024'),
('T0025', 'P0048'),
('T0026', 'P0064'),
('T0027', 'P0003'),
('T0028', 'P0018'),
('T0029', 'P0012'),
('T0030', 'P0046'),
('T0031', 'P0032'),
('T0032', 'P0022'),
('T0034', 'P0061'),
('T0034', 'P0080'),
('T0034', 'P0004'),
('T0034', 'P0067'),
('T0034', 'P0003'),
('T0036', 'P0042'),
('T0037', 'P0012'),
('T0038', 'P0056'),
('T0039', 'P0025'),
('T0040', 'P0033'),
('T0041', 'P0033'),
('T0042', 'P0052'),
('T0042', 'P0067'),
('T0043', 'P0039'),
('T0043', 'P0041'),
('T0043', 'P0066'),
('T0043', 'P0072'),
('T0043', 'P0080'),
('T0044', 'P0032'),
('T0044', 'P0047'),
('T0045', 'P0060'),
('T0046', 'P0028'),
('T0046', 'P0065'),
('T0047', 'P0058'),
('T0048', 'P0035'),
('T0048', 'P0071'),
('T0049', 'P0068'),
('T0049', 'P0079'),
('T0050', 'P0024'),
('T0050', 'P0051'),
('T0051', 'P0018'),
('T0051', 'P0038'),
('T0052', 'P0022'),
('T0052', 'P0064'),
('T0053', 'P0055'),
('T0053', 'P0077'),
('T0054', 'P0048'),
('T0055', 'P0029'),
('T0055', 'P0037'),
('T0056', 'P0049'),
('T0057', 'P0036'),
('T0057', 'P0044'),
('T0058', 'P0046'),
('T0059', 'P0021'),
('T0060', 'P0016'),
('T0060', 'P0061'),
('T0061', 'P0054'),
('T0062', 'P0043'),
('T0063', 'P0025'),
('T0063', 'P0050'),
('T0064', 'P0027'),
('T0064', 'P0057'),
('T0065', 'P0045'),
('T0066', 'P0053'),
('T0066', 'P0078'),
('T0067', 'P0014'),
('T0068', 'P0059'),
('T0069', 'P0020'),
('T0070', 'P0030'),
('T0070', 'P0063'),
('T0071', 'P0023'),
('T0072', 'P0031'),
('T0072', 'P0069'),
('T0073', 'P0019'),
('T0074', 'P0026'),
('T0075', 'P0075'),
('T0076', 'P0015'),
('T0077', 'P0042'),
('T0078', 'P0040'),
('T0079', 'P0034'),
('T0080', 'P0049');


-- RUN TO CALCULATE AND INSERT THE TOTALPRICE
update transactions
set t_totalprice = tt.evenmoretotalprice from (
	select *, coalesce(pc_serviceprice, 0) + coalesce(totalprice, 0) as evenmoretotalprice from (
		select t_id, pc_serviceprice, sum(p_price) as totalprice from transactions t
		left join computer c on t.computer_pc_id = c.pc_id
		left join transactions_product tp on t.t_id = tp.transactions_t_id
		left join product p on tp.product_p_id = p.p_id
		group by t_id, pc_serviceprice
		order by t_id
	)
) as tt
where transactions.t_id = tt.t_id

select * from transactions
select * from computer
select * from supplier
select * from product
select * from employee
select * from customer
select * from transactions_product

-- 1
-- Name and Nik of PC Mechanics who've worked on PCs that gets slow and PCs that has booting issues and has a service price of over 50k IDR
select e_name, e_nik from computer 
join transactions on computer.pc_id = transactions.computer_pc_id
join employee on transactions.employee_e_nik = employee.e_nik
where pc_issue like '%slow%' or pc_issue like '%Slow%' or pc_issue like '%boot%' and pc_serviceprice > 50000.00

-- 2
-- List the 10 most bought item from most bought to least and show the Name and ID of the Product
select count(product_p_id) as bought, product_p_id, p_name from transactions_product
join product on transactions_product.product_p_id = p_id
group by product_p_id, p_name
order by bought desc
limit 10

-- 3
-- List the cashiers who has assisted any transactions made on january 2023
select e_name, e_phone from employee where
e_nik in (
	select employee_e_nik from transactions
	where extract(month from t_date) = 1 and extract(year from t_date) = 2023
	group by employee_e_nik
) and e_position = 'Cashier'

-- 4
-- List 10 of the Customer's name, their customer id, and the amount of items they've bought from the store and sort it by the most items bought to the least
select c_name, c_id, totalbought from (
	select customer_c_id, count(product_p_id) as totalbought from transactions
	join transactions_product on transactions.t_id = transactions_product.transactions_t_id
	group by customer_c_id
) as tmp
join customer on tmp.customer_c_id = customer.c_id
order by totalbought desc
limit 10

-- 5
-- Find the percentage of customer for each transaction method on april 2023 (sort by percentage desc)
-- first transaction method, second perentage (columns)
select t_method, 100.0 * count(t_method)/total as percentage from (
	select t_method, count(t_method) over () as total from transactions where
	extract(month from t_date) = 4 and extract(year from t_date) = 2023
)
group by t_method, total
order by percentage desc;

select t_method, 100.0 * count(t_method)/sum(count(t_method)) over () as percentage from transactions where
extract(month from t_date) = 4 and extract(year from t_date) = 2023
group by t_method
order by percentage desc;

select t_method, count(t_method) as counts, count(t_method) over () as total from transactions where
extract(month from t_date) = 4 and extract(year from t_date) = 2023
group by t_method

select t_method, count(t_method) as total, count(t_method) as methods from transactions where
extract(month from t_date) = 4 and extract(year from t_date) = 2023
group by t

SELECT
    s.s_name,
    ROUND(SUM(t.t_totalprice) / (SELECT SUM(t.t_totalprice) FROM transactions) * 100, 2) AS percentage
FROM supplier s
JOIN product p ON p.supplier_s_id = s.s_id
join transactions_product tp on p.p_id = tp.product_p_id
JOIN transactions t ON tp.transactions_t_id = t.t_id
WHERE p.p_type IN ('Storage', 'GPU')
GROUP BY s.s_name
ORDER BY percentage DESC;

select * from transactions

SELECT *
FROM supplier s
JOIN product p ON p.supplier_s_id = s.s_id
join transactions_product tp on p.p_id = tp.product_p_id
JOIN transactions t ON tp.transactions_t_id = t.t_id
WHERE p.p_type IN ('Storage', 'GPU')
GROUP BY s.s_name
ORDER BY percentage DESC;



--5 find the percentage of product for each customer who lives in countyland, sort by desc order by the percentage
-- order by custommer id, customer address, percentage of product.
SELECT
    c.c_id AS customer_id,
    c.c_address AS customer_address,
    COUNT(tp.product_p_id) * 100.0 / COUNT(DISTINCT t.t_id) AS percentage_of_product
FROM
    customer c
LEFT JOIN transactions t ON c.c_id = t.customer_c_id
LEFT JOIN transactions_product tp ON t.t_id = tp.transactions_t_id
WHERE
    c.c_address LIKE '%Countyland%'
GROUP BY
    c.c_id, c.c_address
ORDER BY
    percentage_of_product DESC;
	
SELECT c_id, c_address, 100.0 * count(product_p_id)/count(product_p_id) over() as total FROM(
	select ()
)
LEFT JOIN transactions t ON c.c_id = t.customer_c_id
LEFT JOIN transactions_product tp ON t.t_id = tp.transactions_t_id
WHERE
    c.c_address LIKE '%Countyland%'
GROUP BY
    c.c_id, c.c_address, total
ORDER BY
    percentage_of_product DESC;
	
	
select
	c.c_id AS customer_id,
    c.c_address AS customer_address,
    COUNT(tp.product_p_id) * 100.0 / SUM(COUNT(DISTINCT tp.product_p_id)) OVER () AS percentage_of_product
FROM
    customer c
LEFT JOIN transactions t ON c.c_id = t.customer_c_id
LEFT JOIN transactions_product tp ON t.t_id = tp.transactions_t_id
WHERE
    c.c_address LIKE '%Countyland%'
GROUP BY
    c.c_id, c.c_address
ORDER BY
    percentage_of_product DESC;
	
	
SELECT s_id, s_name, round(100.0 * sum(t_totalprice) / sum(sum(t_totalprice)) over ()) as percentage FROM supplier s
JOIN product p ON p.supplier_s_id = s.s_id
JOIN transactions_product tp on p.p_id = tp.product_p_id
JOIN transactions t ON tp.transactions_t_id = t.t_id
WHERE p.p_type IN ('Storage', 'GPU')
GROUP BY s_id, s_name
ORDER BY percentage DESC;

--5
-- find the percentage of emplyees for each product that has id between id 40 to 45 shorten by desc order
-- id product, percentage of employee

SELECT p.p_id, 100.0 * COUNT(DISTINCT t.employee_e_nik) / COUNT(t.t_id) AS e_percentage
FROM product p
JOIN transactions_product tp ON p.p_id = tp.product_p_id
JOIN transactions t ON tp.transactions_t_id = t.t_id
WHERE CAST(SUBSTRING(p.p_id FROM 2) AS INTEGER) BETWEEN 40 AND 45
GROUP BY p.p_id ORDER BY e_percentage desc;

SELECT p.p_id, 100.0 * count(employee_e_nik) / sum(count(employee_e_nik)) over () as e_percentage
FROM product p
JOIN transactions_product tp ON p.p_id = tp.product_p_id
JOIN transactions t ON tp.transactions_t_id = t.t_id
WHERE CAST(SUBSTRING(p.p_id FROM 2) AS INTEGER) BETWEEN 40 AND 45
GROUP BY p.p_id
order by e_percentage;