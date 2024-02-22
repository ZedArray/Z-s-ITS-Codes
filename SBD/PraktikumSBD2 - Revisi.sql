-- 1
create table pelanggan(
	p_id char(16) not null primary key,
	p_nama varchar(60) not null,
	p_no_telp varchar(15) not null,
	p_email varchar(256),
	p_alamat varchar(100) not null
);

create table mobil(
	mb_vin char(17) not null primary key,
	mb_merk varchar(20) not null,
	mb_tipe varchar(30) not null,
	mb_tahun integer not null,
	mb_warna varchar(20) not null,
	mb_p_id char(16) not null,
	foreign key (mb_p_id) references pelanggan (p_id)
);

create table tiket_servis(
	ts_id char(8) not null primary key,
	ts_waktu_masuk timestamp not null default current_timestamp,
	ts_waktu_keluar timestamp default current_timestamp,
	ts_deskripsi varchar(400) not null,
	ts_komentar varchar(400),
	ts_p_id char(16) not null,
	ts_mb_vin char(17) not null,
	foreign key (ts_p_id) references pelanggan (p_id),
	foreign key (ts_mb_vin) references mobil (mb_vin)
);

create table mekanik(
	mk_id char(6) not null primary key,
	mk_nama varchar(60) not null
);

create table suku_cadang(
	sc_id char(7) not null primary key,
	sc_nama varchar(120) not null,
	sc_deskripsi varchar(100) not null,
	sc_harga decimal(10,2) not null
);

create table mekanik_servis(
	mksv_mk_id char(6) not null,
	mksv_ts_id char(8) not null,
	primary key(mksv_mk_id, mksv_ts_id),
	foreign key (mksv_mk_id) references mekanik (mk_id),
	foreign key (mksv_ts_id) references tiket_servis (ts_id)
);

create table suku_cadang_servis(
	scsv_ts_id char(8) not null,
	scsv_sc_id char(7) not null,
	primary key(scsv_ts_id, scsv_sc_id),
	foreign key (scsv_ts_id) references tiket_servis (ts_id),
	foreign key (scsv_sc_id) references suku_cadang (sc_id)
);


-- 2
create table supplier(
	sp_id char(6) not null primary key,
	sp_nama varchar(60) not null,
	sp_no_telp varchar(15) not null,
	sp_email varchar(256) not null,
	sp_alamat varchar(100) not null
);

-- 3
alter table mekanik rename to pegawai
create table posisi(
	ps_id CHAR(6) not null primary key,
	ps_nama VARCHAR(15) not null
);

alter table pegawai
add column posisi_ps_id char(6) not null,
add constraint pegawai_posisi_fk foreign key (posisi_ps_id) references posisi (ps_id);


-- 4
drop table posisi cascade;
alter table pegawai
add column mk_posisi varchar(15) not null;
alter table pegawai
drop column posisi_ps_id;


-- 5
insert into pelanggan (p_id, p_nama, p_no_telp, p_email, p_alamat) values
('3225011201880002', 'Andy Williams', '62123456789', 'andy@gmail.com', 'Jl. Apel no 1'),
('3525010706950001', 'Marshall Paul', '621451871011', 'paulan@gmail.com', 'Jl. Jeruk no 12'),
('3525016005920002', 'Kazuya Tanaka', '62190129190', 'tanaka@gmail.com', 'Jl. JKT no 48'),
('3975311107780001', 'Budi Prutomo', '621545458901', null , 'Jl. Nanas no 45'),
('3098762307810002', 'Razai Ambudi', '621898989102', null , 'Jl. Mangga no 2');

insert into mobil (mb_vin, mb_merk, mb_tipe, mb_tahun, mb_warna, mb_p_id) values
('JN8AZ1MW4BW678706', 'Nissan', 'Murano', '2011', 'biru', '3525010706950001'),
('2LMTJ8JP0GSJ00175', 'Lincoln', 'MKX', '2016', 'merah', '3525016005920002'),
('ZFF76ZHT3E0201920', 'Ferrari', 'Ferrari', '2014', 'merah', '3975311107780001'),
('1HGCP26359A157554', 'Honda', 'Accord', '2009', 'hitam', '3225011201880002'),
('5YJSA1DN5CFP01785', 'Tesla', 'Model S', '2012', 'putih', '3098762307810002');

insert into pegawai (mk_id, mk_nama, mk_posisi) values
('MK0001', 'Walter Jones', 'mekanik'),
('MK0002', 'Kentaki Veraid', 'kasir'),
('MK0003', 'Leo', 'mekanik'),
('MK0004', 'Reyhand Janita', 'pencuci'),
('MK0005', 'Elizabeth Alexandra', 'mekanik');

insert into supplier (sp_id, sp_nama, sp_no_telp, sp_email, sp_alamat) values
('SP0001', 'Indotrading', '6282283741247', 'indotrading@rocketmail.com', 'Jl. Bambu no 5'),
('SP0002', 'Jayasinda', '628227428238', 'Jayasinda@yahoo.com', 'Jl. Padi no 12'),
('SP0003', 'SAS Autoparts', '6282212382311', 'sasparts@gmail.com', 'Jl. Sorghum no 24');

insert into suku_cadang(sc_id, sc_nama, sc_deskripsi, sc_harga) values
('SC00001', 'Damper', 'Damper Per Belakang Original', 800000.00),
('SC00002', 'Coil Ignition', 'Coil Ignition Denso Jepang', 550000.00),
('SC00003', 'Selang Filter', 'Selang Filter Udara Original', 560000),
('SC00004', 'Bushing', 'Bushing Upper Arm Original', 345000.00),
('SC00005', 'Radiator Racing', 'Radiator Racing Kotorad Manual Diesel', 6750000.00);

insert into tiket_servis (ts_id, ts_waktu_masuk, ts_waktu_keluar, ts_deskripsi, ts_komentar, ts_p_id, ts_mb_vin) values
('TS000001', '2023-11-05 08:00:00', '2023-11-05 16:30:00', 'Mobil mengalami getaran yang tidak normal saat berkendara. Untuk memperbaikinya, kami akan mengganti damper yang aus dan juga bushing yang telah rusak.', 'Saya sangat puas dengan perbaikan ini. Mobil saya sekarang berjalan lebih halus dan getarannya hilang. Terima kasih atas pelayanan yang baik!', '3098762307810002', '5YJSA1DN5CFP01785');

insert into tiket_servis (ts_id, ts_waktu_masuk, ts_waktu_keluar, ts_deskripsi, ts_komentar, ts_p_id, ts_mb_vin) values
('TS000002', '2023-11-05 09:15:00', '2023-11-05 17:45:00', 'Mesin mobil sering mati secara tiba-tiba atau tidak berjalan dengan baik. Permasalahannya terletak pada coil ignition yang bermasalah. Kami akan menggantinya dan melakukan pengaturan ulang untuk memastikan kinerja mesin yang lebih baik.', 'Mesin mobil saya sekarang berjalan seperti baru lagi. Tidak ada lagi mati mendadak, dan kinerjanya sangat baik. Pelayanan yang cepat dan profesional.', '3975311107780001', 'ZFF76ZHT3E0201920'),

('TS000003', '2023-11-06 10:30:00', '2023-11-06 18:15:00', 'Untuk meningkatkan kinerja pendinginan mesin, kami akan membersihkan radiator dan memeriksa apakah ada kerusakan atau kebocoran. Jika diperlukan, kami akan mengganti komponen yang rusak.', 'Mobil saya sekarang tidak lagi mengalami masalah panas berlebihan. Radiator berfungsi dengan baik, dan saya merasa aman saat berkendara. Terima kasih atas perbaikan yang berkualitas', '3525016005920002', '2LMTJ8JP0GSJ00175'),

('TS000004', '2023-11-06 11:45:00', '2023-11-06 19:30:00', 'Mobil mengalami masalah saat memasok bahan bakar ke mesin. Masalah ini terjadi karena selang filter bahan bakar yang tersumbat. Kami akan menggantinya sehingga aliran bahan bakar menjadi lancar kembali.', 'Setelah penggantian selang filter bahan bakar, mobil saya kembali berjalan dengan lancar. Tidak ada lagi masalah pengiriman bahan bakar. Pelayanan yang sangat membantu', '3525010706950001', 'JN8AZ1MW4BW678706'),

('TS000005', '2023-11-06 12:30:00', '2023-11-06 20:00:00', 'Mobil akan menjalani pemeliharaan komprehensif, termasuk pemeriksaan seluruh sistem. Ini termasuk penggantian damper yang aus, coil ignition yang bermasalah, serta pemeriksaan dan perawatan selang filter dan radiator racing. Semua suku cadang yang perlu diganti akan diperbaiki agar mobil berfungsi seperti semula.', 'Pemeliharaan komprehensif yang telah dilakukan membuat mobil saya seperti baru. Semua masalah telah diperbaiki, dan saya merasa yakin dengan kualitas perbaikan yang diberikan. Terima kasih atas kerja kerasnya', '3225011201880002', '1HGCP26359A157554');

insert into mekanik_servis (mksv_ts_id, mksv_mk_id) values
('TS000001', 'MK0005'),
('TS000002', 'MK0003'),
('TS000002', 'MK0004'),
('TS000003', 'MK0005'),
('TS000004', 'MK0003'),
('TS000005', 'MK0001'),
('TS000005', 'MK0005'),
('TS000005', 'MK0004');

insert into suku_cadang_servis (scsv_ts_id, scsv_sc_id) values
('TS000001', 'SC00001'),
('TS000001', 'SC00004'),
('TS000002', 'SC00002'),
('TS000003', 'SC00005'),
('TS000004', 'SC00003'),
('TS000005', 'SC00001'),
('TS000005', 'SC00002'),
('TS000005', 'SC00003'),
('TS000005', 'SC00005');

-- 6
update tiket_servis set ts_waktu_keluar = current_timestamp

-- 7
update pelanggan set
p_nama = 'Andi Williams',
p_email = 'andi@bing.com',
p_alamat = 'Jl. Koreka no 15'
where p_id = '3225011201880002';

-- 8
alter table suku_cadang
add column supplier_sp_id char(6),
add constraint supplier_sc_fk foreign key (supplier_sp_id) references supplier (sp_id);

update suku_cadang set supplier_sp_id = 'SP0001'
where sc_id in ('SC00004');

update suku_cadang set supplier_sp_id = 'SP0002'
where sc_id in ('SC00001', 'SC00003');

update suku_cadang set supplier_sp_id = 'SP0003'
where sc_id in ('SC00002', 'SC00005');

alter table suku_cadang
alter column supplier_sp_id set not null;


-- 9
update suku_cadang set
sc_harga = sc_harga * 1.1
where sc_harga > 500000.00

-- 10
insert into tiket_servis (ts_id, ts_waktu_masuk, ts_deskripsi, ts_p_id, ts_mb_vin) values
('TS000006', '2023-11-10 09:05:00', 'Mobil mengalami kerusakan damper belakang. Terdapat kebocoran cairan hidrolik dan kondisi damper sudah aus. Kami akan mengganti damper belakang', '3525016005920002', '2LMTJ8JP0GSJ00175');
insert into mekanik_servis (mksv_ts_id, mksv_mk_id) values
('TS000006', 'MK0001');
insert into suku_cadang_servis (scsv_ts_id, scsv_sc_id) values
('TS000006', 'SC00001');

-- 11
update tiket_servis set
ts_waktu_keluar = current_timestamp,
ts_waktu_masuk = '2023-11-10 09:05:00',
ts_komentar = 'Bruh, my mechanic scratched my car'
where ts_id = 'TS000006';

delete from mekanik_servis where
mksv_mk_id = 'MK0001';
delete from pegawai where
mk_nama = 'Walter Jones';

-- 12
truncate table mekanik_servis;



select * from mekanik_servis;
select * from mobil;
select * from pegawai;
select * from pelanggan;
select * from suku_cadang;
select * from suku_cadang_servis;
select * from supplier;
select * from tiket_servis;