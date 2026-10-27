// --- CẤU TRÚC DỮ LIỆU ---

class Node {
    constructor(ten, sdt) {
        this.duLieu = { ten, sdt };
        this.prev = null;
        this.next = null;
    }
}

class DanhBa {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    themLienHe(ten, sdt) {
        const moi = new Node(ten, sdt);
        if (this.head === null) {
            this.head = moi;
            this.tail = moi;
        } else {
            moi.prev = this.tail;
            this.tail.next = moi;
            this.tail = moi;
        }
        logConsole("Them lien he thanh cong!");
    }

    xoaLienHe(sdt) {
        let p = this.head;
        while (p !== null && p.duLieu.sdt !== sdt) {
            p = p.next;
        }
        if (p === null) {
            logConsole("Khong tim thay lien he!");
            return false;
        }
        if (p.prev !== null) {
            p.prev.next = p.next;
        } else {
            this.head = p.next;
        }
        if (p.next !== null) {
            p.next.prev = p.prev;
        } else {
            this.tail = p.prev;
        }
        logConsole("Xoa lien he thanh cong!");
        return true;
    }

    SapXepDanhBa() {
        if (this.head === null || this.head.next === null) return;
        let swapped;
        let lastPtr = null;
        do {
            swapped = false;
            let p = this.head;
            while (p.next !== lastPtr) {
                if (p.duLieu.ten.localeCompare(p.next.duLieu.ten, 'vi', { sensitivity: 'base' }) > 0) {
                    let temp = p.duLieu;
                    p.duLieu = p.next.duLieu;
                    p.next.duLieu = temp;
                    swapped = true;
                }
                p = p.next;
            }
            lastPtr = p;
        } while (swapped);
        logConsole("-> Da sap xep danh ba theo ten thanh cong!");
    }

    getArrayForward() {
        const arr = [];
        let p = this.head;
        while (p !== null) {
            arr.push(p.duLieu);
            p = p.next;
        }
        return arr;
    }

    getArrayBackward() {
        const arr = [];
        let p = this.tail;
        while (p !== null) {
            arr.push(p.duLieu);
            p = p.prev;
        }
        return arr;
    }
}

// --- LỊCH SỬ CUỘC GỌI ---
class NodeLichSu {
    constructor(sdt) {
        this.sdt = sdt;
        this.next = null;
    }
}

class LichSuCuocGoi {
    constructor() {
        this.head = null;
    }

    ghiNhanCuocGoi(sdt) {
        const nodeMoi = new NodeLichSu(sdt);
        nodeMoi.next = this.head;
        this.head = nodeMoi;
        logConsole(`Dang goi toi so: ${sdt}...`);
        logConsole("[Lich su] Da ghi nhan cuoc goi thanh cong!");
    }

    getArrayHistory() {
        const arr = [];
        let p = this.head;
        while (p !== null) {
            arr.push(p.sdt);
            p = p.next;
        }
        return arr;
    }
}

// --- BIẾN TOÀN CỤC ---
const danhBa = new DanhBa();
const lichSu = new LichSuCuocGoi();
let isDuyetXuoi = true; // Chế độ duyệt mặc định: Xuôi

// --- UTILS & LOG ---
function logConsole(message) {
    const logBox = document.getElementById("terminal-log");
    const time = new Date().toLocaleTimeString();
    logBox.innerHTML += `<div><span class="text-slate-500">[${time}]</span> ${message}</div>`;
    logBox.scrollTop = logBox.scrollHeight;
}

// --- RENDER DỮ LIỆU ---

function render() {
    renderDanhBa();
    renderVisualizer();
    renderLichSu();
}

function renderDanhBa() {
    const container = document.getElementById("container-danh-ba");
    const countEl = document.getElementById("count-lien-he");
    const labelEl = document.getElementById("label-huong-duyet");
    const searchVal = document.getElementById("input-tim-kiem").value.trim().toLowerCase();

    let list = isDuyetXuoi ? danhBa.getArrayForward() : danhBa.getArrayBackward();

    // Lọc theo tiền tố tìm kiếm (TimKiemTheoTen)
    if (searchVal) {
        list = list.filter(lh => lh.ten.toLowerCase().startsWith(searchVal));
    }

    countEl.innerText = `${list.length} liên hệ`;
    labelEl.innerHTML = isDuyetXuoi 
        ? `<i class="fa-solid fa-arrow-down-short-wide"></i> Danh Sách Liên Hệ (Duyệt Xuôi - Head &rarr; Tail)` 
        : `<i class="fa-solid fa-arrow-up-wide-short"></i> Danh Sách Liên Hệ (Duyệt Ngược - Tail &rarr; Head)`;

    if (list.length === 0) {
        container.innerHTML = `
            <div class="col-span-2 text-center py-8 text-slate-500 text-sm">
                <i class="fa-solid fa-address-book text-3xl mb-2 text-slate-600 block"></i>
                Danh bạ trống hoặc không tìm thấy liên hệ phù hợp!
            </div>`;
        return;
    }

    container.innerHTML = list.map((lh, index) => `
        <div class="node-card bg-slate-950 border border-slate-800 hover:border-indigo-500/50 p-3 rounded-lg flex items-center justify-between transition group">
            <div class="flex items-center space-x-3">
                <div class="w-9 h-9 rounded-full bg-indigo-950 border border-indigo-700/40 text-indigo-400 font-bold flex items-center justify-center text-sm">
                    ${index + 1}
                </div>
                <div>
                    <h4 class="font-semibold text-sm text-slate-200 group-hover:text-indigo-300 transition">${lh.ten}</h4>
                    <p class="text-xs text-slate-400 font-mono"><i class="fa-solid fa-phone text-[10px] me-1 text-slate-500"></i>${lh.sdt}</p>
                </div>
            </div>
            <div class="flex items-center space-x-1">
                <button onclick="goiTrựcTiếp('${lh.sdt}')" title="Gọi số này" class="p-1.5 hover:bg-emerald-950 text-slate-400 hover:text-emerald-400 rounded transition">
                    <i class="fa-solid fa-phone text-xs"></i>
                </button>
                <button onclick="xoaTrựcTiếp('${lh.sdt}')" title="Xóa liên hệ" class="p-1.5 hover:bg-rose-950 text-slate-400 hover:text-rose-400 rounded transition">
                    <i class="fa-solid fa-trash-can text-xs"></i>
                </button>
            </div>
        </div>
    `).join("");
}

function renderVisualizer() {
    const container = document.getElementById("visualizer-nodes");
    const arr = danhBa.getArrayForward();

    if (arr.length === 0) {
        container.innerHTML = `<span class="text-xs text-slate-500 italic">Danh sách liên kết rỗng (head = NULL, tail = NULL)</span>`;
        return;
    }

    let html = "";
    arr.forEach((lh, idx) => {
        const isHead = idx === 0;
        const isTail = idx === arr.length - 1;

        html += `
            <div class="flex items-center gap-2 flex-shrink-0">
                <div class="bg-slate-950 border ${isHead || isTail ? 'border-indigo-500' : 'border-slate-800'} p-2.5 rounded-lg shadow min-w-[130px] text-center relative">
                    ${isHead ? '<span class="absolute -top-2 left-2 bg-indigo-600 text-[9px] px-1.5 py-0.5 rounded text-white font-bold">HEAD</span>' : ''}
                    ${isTail ? '<span class="absolute -top-2 right-2 bg-amber-600 text-[9px] px-1.5 py-0.5 rounded text-white font-bold">TAIL</span>' : ''}
                    <div class="text-xs font-bold text-slate-200 truncate mt-1">${lh.ten}</div>
                    <div class="text-[10px] font-mono text-indigo-400">${lh.sdt}</div>
                    <div class="flex justify-between border-t border-slate-800/80 mt-1.5 pt-1 text-[9px] font-mono text-slate-500">
                        <span>p: ${isHead ? 'NULL' : '&larr;'}</span>
                        <span>n: ${isTail ? 'NULL' : '&rarr;'}</span>
                    </div>
                </div>
                ${!isTail ? `<div class="text-indigo-400 font-bold text-xs flex items-center"><i class="fa-solid fa-arrows-left-right"></i></div>` : ''}
            </div>
        `;
    });

    container.innerHTML = html;
}

function renderLichSu() {
    const container = document.getElementById("container-lich-su");
    const list = lichSu.getArrayHistory();

    if (list.length === 0) {
        container.innerHTML = `<li class="text-slate-500 italic text-center py-4">[Lich su] Chua co cuoc goi nao duoc ghi nhan!</li>`;
        return;
    }

    container.innerHTML = list.map((sdt, idx) => `
        <li class="bg-slate-950 border border-slate-800 px-3 py-2 rounded flex items-center justify-between">
            <span class="text-slate-400 font-mono"><span class="text-indigo-400 font-bold">${idx + 1}.</span> ${sdt}</span>
            <span class="text-[10px] text-emerald-400 bg-emerald-950/80 border border-emerald-800 px-1.5 py-0.5 rounded">Đã gọi</span>
        </li>
    `).join("");
}

// --- EVENT LISTENERS & CÁC HÀM XỬ LÝ ---

document.getElementById("form-lien-he").addEventListener("submit", (e) => {
    e.preventDefault();
    const ten = document.getElementById("input-ten").value.trim();
    const sdt = document.getElementById("input-sdt").value.trim();
    if (ten && sdt) {
        danhBa.themLienHe(ten, sdt);
        document.getElementById("input-ten").value = "";
        document.getElementById("input-sdt").value = "";
        render();
    }
});

document.getElementById("btn-goi-dien").addEventListener("click", () => {
    const sdtBox = document.getElementById("dial-sdt");
    const sdt = sdtBox.value.trim();
    if (sdt) {
        lichSu.ghiNhanCuocGoi(sdt);
        sdtBox.value = "";
        render();
    }
});

function goiTrựcTiếp(sdt) {
    document.getElementById("dial-sdt").value = sdt;
    lichSu.ghiNhanCuocGoi(sdt);
    render();
}

document.getElementById("btn-xoa").addEventListener("click", () => {
    const sdt = document.getElementById("input-xoa-sdt").value.trim();
    if (sdt) {
        danhBa.xoaLienHe(sdt);
        document.getElementById("input-xoa-sdt").value = "";
        render();
    }
});

function xoaTrựcTiếp(sdt) {
    if (confirm(`Bạn có chắc muốn xóa số ${sdt}?`)) {
        danhBa.xoaLienHe(sdt);
        render();
    }
}

document.getElementById("btn-sap-xep").addEventListener("click", () => {
    danhBa.SapXepDanhBa();
    render();
});

document.getElementById("btn-duyet-xuoi").addEventListener("click", () => {
    isDuyetXuoi = true;
    document.getElementById("btn-duyet-xuoi").classList.add("active", "bg-indigo-600", "text-white");
    document.getElementById("btn-duyet-xuoi").classList.remove("bg-slate-800", "text-slate-400");
    document.getElementById("btn-duyet-nguoc").classList.remove("active", "bg-indigo-600", "text-white");
    document.getElementById("btn-duyet-nguoc").classList.add("bg-slate-800", "text-slate-400");
    logConsole("================ DANH SACH LIEN HE (DUYET XUOI) ================");
    render();
});

document.getElementById("btn-duyet-nguoc").addEventListener("click", () => {
    isDuyetXuoi = false;
    document.getElementById("btn-duyet-nguoc").classList.add("active", "bg-indigo-600", "text-white");
    document.getElementById("btn-duyet-nguoc").classList.remove("bg-slate-800", "text-slate-400");
    document.getElementById("btn-duyet-xuoi").classList.remove("active", "bg-indigo-600", "text-white");
    document.getElementById("btn-duyet-xuoi").classList.add("bg-slate-800", "text-slate-400");
    logConsole("================ DANH SACH LIEN HE (DUYET NGUOC) ================");
    render();
});

document.getElementById("input-tim-kiem").addEventListener("input", (e) => {
    const val = e.target.value.trim();
    if (val) {
        logConsole(`Ket qua tim kiem voi tenCantim '${val}'...`);
    }
    renderDanhBa();
});

document.getElementById("btn-clear-log").addEventListener("click", () => {
    document.getElementById("terminal-log").innerHTML = "";
});

// --- GHI FILE & ĐỌC FILE TXT ---

document.getElementById("btn-ghi-file").addEventListener("click", () => {
    const list = danhBa.getArrayForward();
    let fileContent = "";
    list.forEach(lh => {
        fileContent += `${lh.ten}
${lh.sdt}
`;
    });

    const blob = new Blob([fileContent], { type: "text/plain;charset=utf-8" });
    const a = document.createElement("a");
    a.href = URL.createObjectURL(blob);
    a.download = "danhba.txt";
    a.click();
    logConsole("-> Da ghi du lieu danh ba vao file 'danhba.txt' thanh cong!");
});

document.getElementById("btn-doc-file-trigger").addEventListener("click", () => {
    document.getElementById("input-file").click();
});

document.getElementById("input-file").addEventListener("change", (e) => {
    const file = e.target.files[0];
    if (!file) return;

    const reader = new FileReader();
    reader.onload = (evt) => {
        const text = evt.target.result;
        const lines = text.split(/\r?\n/).map(l => l.trim()).filter(l => l !== "");
        
        let dem = 0;
        for (let i = 0; i < lines.length; i += 2) {
            if (lines[i] && lines[i+1]) {
                danhBa.themLienHe(lines[i], lines[i+1]);
                dem++;
            }
        }
        logConsole(`-> Da doc thanh cong ${dem} lien he tu file '${file.name}'!`);
        render();
    };
    reader.readAsText(file);
});

// Init load
render();
logConsole("[He thong] Da khoi tao Danh ba & Lich su cuoc goi !");
