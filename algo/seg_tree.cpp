// Использование:
// SegTree t(n);
// t.update(i, x)
// t.query(l, r)
struct SegTree {
	int n;
	vector<int64_t> t;

	int64_t query(int v, int l, int r, int ql, int qr) {
		if (ql >= qr) {
			// Возвращаем нейтральный элемент
			// Для минимума: INF
			// Для максимума: -INF
			// Для произведения: 1
			// Для произведения матриц: единичная матрица
			// ...
			return 0;
		}
		if (ql == l && qr == r) {
			// Запрос попал на отрезок целиком, возвращаем
			// ответ для отрезка
			return t[v];
		}
		int m = (l + r) / 2;
		int64_t vl = query(v * 2 + 1, l, m, ql, min(qr, m));
		int64_t vr = query(v * 2 + 2, m, r, max(m, ql), qr);
		// Комбинируем два результата
		return vl + vr;
	}

	void update(int v, int l, int r, int i, int x) {
		if (l + 1 == r) {
			// Попали в ячейку с индексом i, обновляем ответ
			t[v] = x;
			return;
		}
		int m = (l + r) / 2;
		if (i < m) {
			update(v * 2 + 1, l, m, i, x);
		} else {
			update(v * 2 + 2, m, r, i, x);
		}
		// После того как обновили ответ в поддереве, необходимо
		// пересчитать ответ в текущей вершине
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}

	SegTree(int n) : n(n), t(4 * n) {}

	int64_t query(int l, int r) {
		return query(0, 0, n, l, r);
	}

	void update(int i, int x) {
		update(0, 0, n, i, x);
	}
};
